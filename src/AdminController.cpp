//
// Created by Nikos on 4/22/2020.
//

#include "AdminController.h"

AdminController::AdminController(FilmRepository* repo) {
    this->films = repo;
}

AdminController::~AdminController() {
	delete this->films;
}

/*
 * This method allows the admin to add a film.
 * @param titel: string, the title of the film
 * @param genre: string, the genre of the film
 * @param year: integer, the publishing year
 * @param likes: integer, the number of likes
 * @param link: string, the link to the trailer
 */
void AdminController::addFilm(std::string titel, std::string genre, int year, int likes, std::string link) {
    // Validating data:
    if(year < 1897 || year > 2020 || likes < 0){
        throw FilmValidatorException("Invalid data!");
    }
    this->films->addFilm(new Film(titel, genre, year, likes, link));
}

/*
 * This method allows the admin to delete a film.
 * A film is unique by its titel and publising year.
 * @param titel: string, the title of the film
 * @param year: integer, the publishing year
 */
void AdminController::deleteFilm(std::string titel, int year) {
    // Validating data:
    if(year < 1897 || year > 2020){
        throw FilmValidatorException("Invalid data!");
    }
    this->films->deleteFilm(titel, year);
}

/*
 * This method allows the admin to modify the genre of a film.
 * A film is unique by its titel and publising year.
 * @param titel: string, the title of the film
 * @param year: integer, the publishing year
 * @param newGenre: string, the genre of the film
 */
void AdminController::modifyGenre(std::string titel, int year, std::string newGenre) {
    // Validating data:
    if(year < 1897 || year > 2020){
        throw FilmValidatorException("Invalid data!");
    }
    this->films->updateGenre(titel, year, newGenre);
}

/*
 * This method allows the admin to modify the title a film.
 * A film is unique by its titel and publising year.
 * @param titel: string, the title of the film
 * @param year: integer, the publishing year
 * @param newTitel: string, the new titel of the film
 */
void AdminController::modifyTitel(std::string titel, int year, std::string newTitel) {
    // Validating data:
    if(year < 1897 || year > 2020){
        throw FilmValidatorException("Invalid data!");
    }
    this->films->updateTitel(titel, year, newTitel);
}

/*
 * This method allows the admin to modify the publishing year of a film.
 * A film is unique by its titel and publising year.
 * @param titel: string, the title of the film
 * @param year: integer, the publishing year
 * @param newYear: integer, the new publishing year
 */
void AdminController::modifyYear(std::string titel, int year, int newYear) {
    // Validating data:
    if(year < 1897 || year > 2020){
        throw FilmValidatorException("Invalid data!");
    }
    this->films->updateErscheinungsjahr(titel, year, newYear);
}

/*
 * This method allows the admin to modify the number of likes of a film.
 * A film is unique by its titel and publising year.
 * @param titel: string, the title of the film
 * @param year: integer, the publishing year
 * @param newLikes: integre, the new number of likes
 */
void AdminController::modifyLikes(std::string titel, int year, int newLikes) {
    // Validating data:
    if(year < 1897 || year > 2020){
        throw FilmValidatorException("Invalid data!");
    }
    this->films->updateAnzahlLikes(titel, year, newLikes);
}

/*
 * This method allows the admin to delete a film.
 * A film is unique by its titel and publising year.
 * @param titel: string, the title of the film
 * @param year: integer, the publishing year
 * @param newLink: string, the new link to the trailer
 */
void AdminController::modufyLink(std::string titel, int year, std::string newLink) {
    // Validating data:
    if(year < 1897 || year > 2020){
        throw FilmValidatorException("Invalid data!");
    }
    this->films->updateTrailer(titel, year, newLink);
}

/*
 * This method shows all the films->
 * @return: a string, the list of films
*/
std::string AdminController::showFilms() {
    std::string filme;
    for(auto & film : this->films->getFilme()){
        // We add the movie.
        filme += film->showFilm() + '\n';
    }
    return filme;
}
