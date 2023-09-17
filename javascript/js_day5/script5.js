let movies = [
    {
        name: 'RRR',
        rating: 7.8,
        Poster: 'https://www.themoviedb.org/t/p/w440_and_h660_face/nEufeZlyAOLqO2brrs0yeF1lgXO.jpg',
        description: 'RRR is a 2022 Indian Telugu-language epic action drama film directed by S. S. Rajamouli, who co-wrote the film with V. Vijayendra Prasad.'
    },

    {
        name: 'The Matrix',
        rating: 9.2,
        Poster: "https://m.media-amazon.com/images/M/MV5BNzQzOTk3OTAtNDQ0Zi00ZTVkLWI0MTEtMDllZjNkYzNjNTc4L2ltYWdlXkEyXkFqcGdeQXVyNjU0OTQ0OTY@._V1_.jpg",
        description: "The Matrix is a 1999 science fiction action film[5][6] written and directed by the Wachowskis"
    },

    {
        name: 'Avengers Endgame',
        rating: 8.4,
        Poster: 'https://upload.wikimedia.org/wikipedia/en/0/0d/Avengers_Endgame_poster.jpg',
        description: 'Avengers: Endgame is a 2019 American superhero film based on the Marvel Comics superhero team the Avengers. '

    },

    {
        name: "Inception",
        rating: 8.8,
        Poster: 'https://upload.wikimedia.org/wikipedia/en/2/2e/Inception_%282010%29_theatrical_poster.jpg',
        description: 'Inception is a 2010 science fiction action film written and directed by Christopher Nolan'
    },

    {
        name: 'Iron Man',
        rating: 7.9,
        Poster: 'https://upload.wikimedia.org/wikipedia/en/4/47/Iron_Man_%28circa_2018%29.png',
        description: 'Iron Man is a superhero appearing in American comic books published by Marvel Comics'
    },

    {
        name: 'Dark knight',
        rating: 9.0,
        Poster: 'https://m.media-amazon.com/images/M/MV5BMTMxNTMwODM0NF5BMl5BanBnXkFtZTcwODAyMTk2Mw@@._V1_FMjpg_UX1000_.jpg',
        description: 'The Dark Knight is a 2008 superhero film directed by Christopher Nolan from a screenplay co-written with his brother Jonathan'
    },

    {
        name: 'Avenger Infinity war',
        rating: 8.4,
        Poster: 'https://upload.wikimedia.org/wikipedia/en/4/4d/Avengers_Infinity_War_poster.jpg',
        description: 'Avengers: Infinity War is a 2018 American superhero film based on the Marvel Comics superhero team the Avengers.'
    },

    {
        name: 'Captain  America: Civil war',
        rating: 7.8,
        Poster: 'https://upload.wikimedia.org/wikipedia/en/5/53/Captain_America_Civil_War_poster.jpg',
        description: "Captain America: Civil War is a 2016 American superhero film based on the Marvel Comics character Captain America, produced by Marvel Studios"
    },

    {
        name: 'Lucy',
        rating: 6.4,
        Poster: "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcT56XQiKYSzGzVS8mkL-alHiyyARFqWYYKjX2SvwBfrUx2yiE9FwcxtBIeBQVL8irRVQro&usqp=CAU",
        description: "Lucy is a 2014 French English-language science fiction action film[5] written and directed by Luc Besson for his company EuropaCorp."
    },

    {
        name: 'Spider Man',
        rating: 7.4,
        Poster: 'https://upload.wikimedia.org/wikipedia/en/6/6c/Spider-Man_%282002_film%29_poster.jpg',
        description: "Spider-Man is a 2002 American superhero film based on the Marvel Comics"

    },

    {
        name: 'Interteller',
        rating: 8.7,
        Poster: 'https://upload.wikimedia.org/wikipedia/en/b/bc/Interstellar_film_poster.jpg',
        description: "Interstellar is a 2014 epic science fiction film co-written, directed, and produced by Christopher Nolan. It stars Matthew McConaughey, Anne Hathaway,"

    },

    {
        name: 'Oppenheimer',
        rating: 8.6,
        Poster: 'https://upload.wikimedia.org/wikipedia/en/4/4a/Oppenheimer_%28film%29.jpg',
        description: "Oppenheimer is a 2023 epic biographical drama film written and directed by Christopher Nolan and starring Cillian Murphy as J. Robert Oppenheimer,"

    }
]


function searchMovie() {
    let moviename = document.getElementById('search').value

    if (moviename !== '') {
               let result = movies.filter(function (movie) {
                   return movie.name.toUpperCase().includes(moviename.toUpperCase())
               })
        displayMovies(result)
    }
    else{
        displayMovies(movies);
    }
}

function displayMovies(data) {

    document.getElementById('movies').innerHTML = ""

    let htmlstring = ``

    for (let i = 0; i < data.length; i++) {
        htmlstring = htmlstring + `
        <div class="movie">
        <div class="overlay">
           <div class="video">
              
           </div>
           <div class="details">
            <h3>${data[i].name}</h3>
            <h4>IMDB:${data[i].rating}</h4>
            <p>${data[i].description}</p>
           </div>
        </div>
        <img class="poster1" src="${data[i].Poster}" alt="${data[i].name}">
    </div>`
    }

    document.getElementById('movies').innerHTML = htmlstring
}

displayMovies(movies)