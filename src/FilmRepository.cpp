//
// Created by Nikos on 4/12/2020.
//
#include "FilmRepository.h"

#include <fstream>
#include <iostream>
#include <algorithm>

// Constructor of class.
FilmRepository::FilmRepository(){
    this->filme = std::vector<Film*>();
    readDatabase();
}

FilmRepository::~FilmRepository() {
	writeDatabase();

	for(Film* f : this->filme)
		delete f;
}

// Helper Methods.
Film* FilmRepository::getFilmBy(std::string titel, int jahr) {
	for(Film* f : this->filme)
		if(f->getTitel() == titel and f->getErscheinungsjahr() == jahr)
			return f;
	return nullptr;
}

// Getter.

/*
    Returns the list of films.
    @return: a vector, the list of films
*/
std::vector<Film*> FilmRepository::getFilme(){
    return this->filme;
}

// Methods.

/*
    Adds a film to the list or throws an error if the film already exists.
    @param film: an object of class Film, a movie to be added
*/
void FilmRepository::addFilm(Film* film){
    // Searches if the film exists.
    for(auto movie = this->filme.begin(); movie != this->filme.end(); ++movie){
        if(film->getTitel() == (*movie)->getTitel() && film->getErscheinungsjahr() == (*movie)->getErscheinungsjahr()){
            // If we found it, then it shows an error.
            throw FilmRepoException("The film already exists!");
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
        if(titel== (*movie)->getTitel() && jahr == (*movie)->getErscheinungsjahr()){
            // If we found it, then we remove it.
            this->filme.erase(movie);
            return;
        }
    }
    // If we have not found it, ..
    throw FilmRepoException("The film was not found!");
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
        if((*movie).getTitel() == titel && (*movie).getErscheinungsjahr() == jahr){
            // If it exists, we modify the title.
        	(*movie).setTitel(newTitel);
            return;
        }
    }
    // Otherwise, if it wasn't found, ..
    throw FilmRepoException("The film was not found!");
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
        if((*movie).getTitel() == titel && (*movie).getErscheinungsjahr() == jahr){
            // If it exists, we modify the title.
        	(*movie).setGenre(newGenre);
        	return;
        }
    }
    // Otherwise, if it wasn't found, ..
    throw FilmRepoException("The film was not found!");
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
        if((*movie).getTitel() == titel && (*movie).getErscheinungsjahr() == jahr){
            // If it exists, we modify the title.
        	(*movie).setErscheinungsjahr(newJahr);
        	return;
        }
    }
    // Otherwise, if it wasn't found, ..
    throw FilmRepoException("The film was not found!");
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
        if((*movie).getTitel() == titel && (*movie).getErscheinungsjahr() == jahr){
            // If it exists, we modify the title.
        	(*movie).setAnzahlLikes(newLikes);
        	return;
        }
    }
    // Otherwise, if it wasn't found, ..
    throw FilmRepoException("The film was not found!");
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
        if((*movie).getTitel() == titel && (*movie).getErscheinungsjahr() == jahr){
            // If it exists, we modify the title.
        	(*movie).setLinkTrailer(newLink);
        	return;
        }
    }
    // Otherwise, if it wasn't found, ..
    throw FilmRepoException("The film was not found!");
}

// ----- Abstract Methods --------------------

/** Read all the films from a local file. */
void FilmRepository::readDatabase() {
	std::string titel;
	std::string genre;
	std::string eJahr;
	std::string likes;
	std::string trailer;

	std::ifstream input("Film.txt");
	if(input.is_open()) {
		while(true) {
			input >> titel >> genre >> eJahr >> likes >> trailer;

			if(input.eof())
				break;

			// Format the strings.
			while(genre.find("-") != std::string::npos)
				genre.replace(genre.find("-"), 1, " ");
			while(titel.find("-") != std::string::npos)
				titel.replace(titel.find("-"), 1, " ");

			this->filme.push_back(new Film(titel, genre, std::stoi(eJahr), std::stoi(likes), trailer));
		}

		input.close();
	} else
        throw DatabaseException("Unable to open FilmDatabase!");
}

/** Write all the films to a local file. */
void FilmRepository::writeDatabase() {
	std::ofstream output("Film.txt", std::ofstream::trunc);
	if(output.is_open()) {
		// Write the new data.
		for(Film* f : this->getFilme()) {
			std::string titel = f->getTitel();
			std::string genre = f->getGenre();

			// Format the strings.
			// This in necessary so we don't need to handle
			// film-types like "science fiction" separately.
			while(genre.find(' ') != std::string::npos)
				genre.replace(genre.find(" "), 1, "-");
			while(titel.find(' ') != std::string::npos)
				titel.replace(titel.find(" "), 1, "-");

			output << titel << " " << genre << " " << std::to_string(f->getErscheinungsjahr()) << " " << std::to_string(f->getAnzahlLikes()) << " " << f->getLinkTrailer() << std::endl;
		}

		output.flush();
		output.close();
	} else
        throw DatabaseException("Unable to open FilmDatabase!");
}
