import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd
import datetime

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///project.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def inbox():
    """Show all the emails received"""
    userId = session["user_id"]
    emailDB = db.execute("SELECT email_id FROM users WHERE id = ?", userId)
    email_id = emailDB[0]["email_id"]
    emails = db.execute("SELECT * FROM emails WHERE recipient = ?", email_id)
    return render_template("inbox.html",emails=emails)


if __name__ =="__main__":
   app.run(debug=false,host='0.0.0.0')


@app.route("/compose", methods=["GET", "POST"])
@login_required
def compose():
    """compose email to someone"""
    if request.method == "GET":
        userId = session["user_id"]
        senderDB = db.execute("SELECT email_id FROM users WHERE id = ?", userId)
        sender = senderDB[0]["email_id"]
        return render_template("compose.html", sender=sender)

    else:
        sender = request.form.get("sender")
        recipient = request.form.get("recipient")
        subject = request.form.get("subject")
        body = request.form.get("body")

        if not sender or not recipient or not subject or not body:
            return apology("No Empty Fields")

        db.execute("INSERT INTO emails (sender, recipient, subject, body) VALUES (?, ?, ?, ?)", sender, recipient, subject, body)

        flash("You Sent the Message!")

        return redirect("/sent")


@app.route("/sent")
@login_required
def sent():
    """Sent the email to someone"""
    userId = session["user_id"]
    emailDB = db.execute("SELECT email_id FROM users WHERE id = ?", userId)
    email_id = emailDB[0]["email_id"]
    emails = db.execute("SELECT * FROM emails WHERE sender = ?", email_id)
    return render_template("sent.html",emails=emails)



@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("email_id"):
            return apology("must provide Email id", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        email = db.execute("SELECT * FROM users WHERE email_id = ?", request.form.get("email_id"))

        # Ensure username exists and password is correct
        if len(email) != 1 or not check_password_hash(email[0]["hash"], request.form.get("password")):
            return apology("invalid Email and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = email[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/email", methods=["POST"])
@login_required
def email():
    """View emails details"""
    if request.method == "POST":
        emailId = request.form.get("emailId")
        emailDetailDB = db.execute("SELECT * FROM emails WHERE id = ?", emailId)
        emailDetail = emailDetailDB[0]
        return render_template("email.html",emailDetail=emailDetail)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        return render_template("register.html")
    else:
        email_id = request.form.get("email_id")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        ## correcting invalid for results to return apology
        if not email_id:
            return apology("Do Not Blank Your Email id")

        if not password:
            return apology("Do Not Blank Password")

        if not confirmation:
            return apology("Do Not Blank Confirmation")

        if password != confirmation:
            return apology("Password Not Matching")

        #generating hash codes for password
        hash = generate_password_hash(password)

        try:
           new_user =  db.execute("INSERT INTO users (email_id, hash) VALUES (?, ?)", email_id, hash)
        except:
            return apology("User Already Exists")

        session["user_id"] = new_user

        #redirect to homepage
        return redirect("/")

@app.route("/reply", methods=["POST"])
@login_required
def reply():
    """Reply the email"""
    if request.method == "POST":
        emailId = request.form.get("emailId")
        emailDetailDB = db.execute("SELECT * FROM emails WHERE id = ?", emailId)
        emailDetail = emailDetailDB[0]
        return render_template("reply.html",emailDetail=emailDetail)