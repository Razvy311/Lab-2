//
// Created by Nikos on 4/12/2020.
//

#ifndef FILMREPOSITORY_H
#define FILMREPOSITORY_H

#include "Film.h"
#include "exceptions.h"
#include "IORepoAbstract.h"

#include <vector>
#include <exception>

class FilmRepository : public IORepoAbstract {
private:
    // Contains the list with all the films.
    std::vector<Film*> filme;
public:
    // Constructor of class.
    FilmRepository();
    ~FilmRepository();

    // Getter.
    std::vector<Film*> getFilme();

    // Helper Methods.
    Film* getFilmBy(std::string titel, int jahr);

    // Methods.
    // Adds a film to the list or throws an error if it already exists.
    void addFilm(Film* film);
    // Deletes a film or throws an error if it doesn't exist.
    void deleteFilm(std::string titel, int jahr);
    // Update:
    // - titel
    void updateTitel(std::string titel, int jahr, std::string newTitel);
    // - genre
    void updateGenre(std::string titel, int jahr, std::string newGenre);
    // - publish year
    void updateErscheinungsjahr(std::string titel, int jahr, int newJahr);
    // - number of lilkes
    void updateAnzahlLikes(std::string titel, int jahr, int newLikes);
    // - link to trailer
    void updateTrailer(std::string titel, int jahr, std::string newLink);

    // Abstract methods.
	void readDatabase();
	void writeDatabase();
};

#endif // FILMREPOSITORY_H
