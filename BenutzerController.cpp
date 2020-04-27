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

BenutzerController::BenutzerController(FilmRepository* fRepo) {
	this->bRepo = new BenutzerRepository();
	this->fRepo = fRepo;
}

std::vector<Film*> BenutzerController::filterByGenre(std::string genre) {
	std::vector<Film*> filme;
	for(Film* film : this->fRepo->getFilme())
		if(film->getGenre().find(genre) != std::string::npos)
			filme.push_back(film);
	return filme;
}

void BenutzerController::removeFilmFromWatchlist(Benutzer* benutzer, Film* film, bool like) {
	benutzer->removeFilm(film);

	if(like)
		this->fRepo->updateAnzahlLikes(film->getTitel(), film->getErscheinungsjahr(), film->getAnzahlLikes() + 1);
}



