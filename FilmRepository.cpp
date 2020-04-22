//
// Created by Nikos on 4/12/2020.
//
#include "FilmRepository.h"
#include <algorithm>

// Constructor of class.
FilmRepository::FilmRepository(){
    this->filme = std::vector<Film>();
    // Creates a list with the initial 10 films.
    this->filme.push_back(Film("film1", "horror", 2001, 120, "www.youtube.com"));
    this->filme.push_back(Film("film2", "romance", 2001, 120, "www.imdb.com"));
    this->filme.push_back(Film("film3", "comedy", 2001, 120, "www.imdb.com"));
    this->filme.push_back(Film("film4", "thriller", 2001, 120, "www.youtube.com"));
    this->filme.push_back(Film("film5", "horror", 2001, 120, "www.pinterest.com"));
    this->filme.push_back(Film("film6", "romance", 2001, 120, "www.youtube.com"));
    this->filme.push_back(Film("film7", "science fiction", 2001, 120, "www.imdb.com"));
    this->filme.push_back(Film("film8", "science fiction", 2001, 120, "www.deviantart.com"));
    this->filme.push_back(Film("film9", "comedy", 2001, 120, "www.youtube.com"));
    this->filme.push_back(Film("film10", "thriller", 2001, 120, "www.youtube.com"));
}

// Getter.

/*
    Returns the list of films.
    @return: a vector, the list of films
*/
std::vector<Film> FilmRepository::getFilme(){
    return this->filme;
}

// Methods.

/*
    Adds a film to the list or throws an error if the film already exists.
    @param film: an object of class Film, a movie to be added
*/
void FilmRepository::addFilm(Film film){
    // Searches if the film exists.
    for(auto movie = this->filme.begin(); movie != this->filme.end(); ++movie){
        if(film.getTitel() == movie->getTitel() && film.getErscheinungsjahr() == movie->getErscheinungsjahr()){
            // If we found it, then it shows an error.
            throw RepoException();
        }
    }
    this->filme.push_back(film);
}

/*
    Deletes a film or throws an error if the film doesn't exist.
    @param titel: a string, the title
    @param jahr: an integer, the publishing year
*/
void FilmRepository::deleteFilm(std::string titel, int jahr){
    // Serches for the film.
    for(auto movie = this->filme.begin(); movie != this->filme.end(); ++movie){
        if(titel== movie->getTitel() && jahr == movie->getErscheinungsjahr()){
            // If we found it, then we remove it.
            this->filme.erase(movie);
            return;
        }
    }
    // If we have not found it, ..
    throw  RepoException();
}

// Update:
// - titel
/*
    Updates the titel.
    @param titel: a string, the title
    @param jahr: an integer, the year
    @param newTitel: a string, the new titel
*/
void FilmRepository::updateTitel(std::string titel, int jahr, std::string newTitel){
    // We search for the movie.
    for(auto & movie : this->filme){
        if(movie.getTitel() == titel && movie.getErscheinungsjahr() == jahr){
            // If it exists, we modify the title.
            movie.setTitel(newTitel);
            return;
        }
    }
    // Otherwise, if it wasn't found, ..
    throw RepoException();
}

// - genre
/*
    Updates the genre.
    @param titel: a string, the title
    @param jahr: an integer, the year
    @param newGenre: a string, the new genre
*/
void FilmRepository::updateGenre(std::string titel, int jahr, std::string newGenre){
    // We search for the movie.
    for(auto & movie : this->filme){
        if(movie.getTitel() == titel && movie.getErscheinungsjahr() == jahr){
            // If it exists, we modify the title.
            movie.setGenre(newGenre);
        }
    }
    // Otherwise, if it wasn't found, ..
    throw RepoException();

}

// - publish year
/*
    Updates the publishing year.
    @param titel: a string, the title
    @param jahr: an integer, the year
    @param newJahr: an integer, the new year
*/
void FilmRepository::updateErscheinungsjahr(std::string titel, int jahr, int newJahr){
    // We search for the movie.
    for(auto & movie : this->filme){
        if(movie.getTitel() == titel && movie.getErscheinungsjahr() == jahr){
            // If it exists, we modify the title.
            movie.setErscheinungsjahr(newJahr);
        }
    }
    // Otherwise, if it wasn't found, ..
    throw RepoException();
}

// - number of lilkes
/*
    Updates the number of likes.
    @param titel: a string, the title
    @param jahr: an integer, the year
    @param newLikes: an integer, the new number of likes
*/
void FilmRepository::updateAnzahlLikes(std::string titel, int jahr, int newLikes){
    // We search for the movie.
    for(auto & movie : this->filme){
        if(movie.getTitel() == titel && movie.getErscheinungsjahr() == jahr){
            // If it exists, we modify the title.
            movie.setAnzahlLikes(newLikes);
        }
    }
    // Otherwise, if it wasn't found, ..
    throw RepoException();
}

// - link to trailer
/*
    Updates the link to the trailer.
    @param titel: a string, the title
    @param jahr: an integer, the year
    @param newLink: a string, the new link to the trailer
*/
void FilmRepository::updateTrailer(std::string titel, int jahr, std::string newLink){
    // We search for the movie.
    for(auto & movie : this->filme){
        if(movie.getTitel() == titel && movie.getErscheinungsjahr() == jahr){
            // If it exists, we modify the title.
            movie.setLinkTrailer(newLink);
        }
    }
    // Otherwise, if it wasn't found, ..
    throw RepoException();
}