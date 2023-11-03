from django.contrib.auth import authenticate, login, logout
from django.db import IntegrityError
from django.http import HttpResponse, HttpResponseRedirect
from django.shortcuts import render
from django.urls import reverse

from .models import User, Category, Listing, Comments, Bid

def index(request):
    activeListings = Listing.objects.filter(isActive=True)
    allCategories = Category.objects.all()
    return render(request, "auctions/index.html", {
        "listings": activeListings,
        "categories": allCategories,
    })

def listing(request, id):
    listingDetails = Listing.objects.get(pk=id) 
    isListingInWatchlist = request.user in listingDetails.watchlist.all()
    allComments = Comments.objects.filter(listing=listingDetails)
    isOwner = request.user.username == listingDetails.owner.username
    return render(request, "auctions/listing.html",{
        "listing": listingDetails,
        "isListingInWatchlist":isListingInWatchlist,
        "allComments": allComments,
        "isOwner": isOwner
    })

def closeAuction(request, id):
    listingData = Listing.objects.get(pk=id)
    listingData.isActive = False
    listingData.save()
    isOwner = request.user.username == listingData.owner.username
    isListingInWatchlist = request.user in listingData.watchlist.all()
    allComments = Comments.objects.filter(listing=listingData)
    return render(request, "auctions/listing.html",{
        "listing": listingData,
         "isListingInWatchlist":isListingInWatchlist,
        "allComments": allComments,
        "isOwner": isOwner,

        "update": True,
        "message": "Congratulations!! Your auction is closed."
    })

def displaywatchlist(request):
    currentUser = request.user
    listings = currentUser.listingWatchlist.all()
    return render(request, "auctions/watchlist.html",{
        "listings": listings
    })

def addComment(request, id):
    currentUser = request.user
    listingdata = Listing.objects.get(pk=id)
    message = request.POST['newComment']

    newComment = Comments(
        author = currentUser,
        listing = listingdata,
        message = message
    )

    newComment.save()

    return HttpResponseRedirect(reverse(listing,args=(id, )))

def addbid(request,id):
    newBid = request.POST['newbid']
    listingData = Listing.objects.get(pk=id)
    isListingInWatchlist = request.user in listingData.watchlist.all()
    allComments = Comments.objects.filter(listing=listingData)
    isOwner = request.user.username == listingData.owner.username
    if int(newBid) > listingData.price.bid:
        updateBid = Bid(user=request.user, bid=int(newBid))
        updateBid.save()
        listingData.price = updateBid
        listingData.save()
        return render(request, "auctions/listing.html", {
            "listing": listingData,
            "message":"Bid was updated successfully",
            "update": True,
            "isListingInWatchlist":isListingInWatchlist,
            "allComments": allComments,
             "isOwner": isOwner
        })
    else:
        return render(request, "auctions/listing.html", {
            "listing": listingData,
            "message":"Bid updated failed",
            "update": False,
            "isListingInWatchlist":isListingInWatchlist,
            "allComments": allComments,
             "isOwner": isOwner
        })

def removewatchlist(request, id):
    listingData = Listing.objects.get(pk=id)
    currentuser = request.user
    listingData.watchlist.remove(currentuser)
    return HttpResponseRedirect(reverse(listing,args=(id, )))

def addwatchlist(request, id):
    listingData = Listing.objects.get(pk=id)
    currentuser = request.user
    listingData.watchlist.add(currentuser)
    return HttpResponseRedirect(reverse(listing,args=(id, )))


def displayCategory(request):
    if request.method == "POST":
        categoryFromform = request.POST['category']
        category = Category.objects.get(categoryName = categoryFromform)
        activeListings = Listing.objects.filter(isActive=True, category=category)
        allCategories = Category.objects.all()
        return render(request, "auctions/index.html", {
            "listings": activeListings,
            "categories": allCategories,
        })

def createListing(request):
    if request.method == "GET":
        allCategories = Category.objects.all()
        return render(request,"auctions/create.html",{
            "categories":allCategories
        })
    else:
        title = request.POST["title"]
        description = request.POST["description"]
        imageurl = request.POST["imageurl"]
        price = request.POST["price"]
        category = request.POST["category"]
        currrentUser = request.user

        categoryData = Category.objects.get(categoryName = category)

        #create a Bid object
        bid = Bid(bid=int(price), user = currrentUser)
        bid.save()
        
        newListing = Listing(
            title = title,
            description= description,
            imageUrl = imageurl,
            price = bid,
            category = categoryData,
            owner = currrentUser
        )

        newListing.save()
        return HttpResponseRedirect(reverse(index))

def login_view(request):
    if request.method == "POST":

        # Attempt to sign user in
        username = request.POST["username"]
        password = request.POST["password"]
        user = authenticate(request, username=username, password=password)

        # Check if authentication successful
        if user is not None:
            login(request, user)
            return HttpResponseRedirect(reverse("index"))
        else:
            return render(request, "auctions/login.html", {
                "message": "Invalid username and/or password."
            })
    else:
        return render(request, "auctions/login.html")


def logout_view(request):
    logout(request)
    return HttpResponseRedirect(reverse("index"))


def register(request):
    if request.method == "POST":
        username = request.POST["username"]
        email = request.POST["email"]

        # Ensure password matches confirmation
        password = request.POST["password"]
        confirmation = request.POST["confirmation"]
        if password != confirmation:
            return render(request, "auctions/register.html", {
                "message": "Passwords must match."
            })

        # Attempt to create new user
        try:
            user = User.objects.create_user(username, email, password)
            user.save()
        except IntegrityError:
            return render(request, "auctions/register.html", {
                "message": "Username already taken."
            })
        login(request, user)
        return HttpResponseRedirect(reverse("index"))
    else:
        return render(request, "auctions/register.html")
