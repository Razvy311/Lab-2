/*
 * BenutzerController.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: root
 */

#include <string>
#include <iostream>
#include <algorithm>

#include "BenutzerController.h"

/**
 * Constructs a new User Controller.
 *
 * @param fRepo
 *            - the repository containing all the available films.
 */
BenutzerController::BenutzerController(FilmRepository* fRepo) {
	this->bRepo = new BenutzerRepository();
	this->fRepo = fRepo;
}

/**
 * Returns a vector contains the pointers of the films with a specific genre.
 *
 * @param genre
 *            - the genre to search for.
 *
 * @return A vector contains the pointers of the films with a specific genre
 */
std::vector<Film*> BenutzerController::filterByGenre(std::string genre) {
	std::vector<Film*> filme;
	for(Film* film : this->fRepo->getFilme())
		if(film->getGenre().find(genre) != std::string::npos)
			filme.push_back(film);
	return filme;
}

/**
 * Removes a film from a users watchlist.
 *
 * @param benutzer
 *            - a pointer to the user from which to remove the film.
 * @param film
 *            - a pointer to the film to remove.
 * @param like
 *            - if the likes of the film should be incremented based on the user choice.
 */
void BenutzerController::removeFilmFromWatchlist(Benutzer* benutzer, Film* film, bool like) {
	benutzer->removeFilm(film);

	if(like)
		this->fRepo->updateAnzahlLikes(film->getTitel(), film->getErscheinungsjahr(), film->getAnzahlLikes() + 1);
}



