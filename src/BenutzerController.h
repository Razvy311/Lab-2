/*
 * BenutzerController.h
 *
 *  Created on: Apr 26, 2020
 *      Author: root
 */

#ifndef BENUTZERCONTROLLER_H
#define BENUTZERCONTROLLER_H

#include "Film.h"
#include "FilmRepository.h"
#include "BenutzerRepository.h"

class BenutzerController {
	private:
		FilmRepository* fRepo;
		BenutzerRepository* bRepo;

	public:
		BenutzerController(FilmRepository* fRepo);
		~BenutzerController();

		std::vector<Film*> filterByGenre(std::string genre);

		// Repo Methods.
		void addUser(std::string vorname, std::string name) { bRepo->addUser(vorname, name); }
		void removeUser(std::string vorname, std::string name) { bRepo->removeUser(vorname, name); }

		void removeFilmFromWatchlist(Benutzer* benutzer, Film* film, bool like);

		void saveToCSV(Benutzer* benutzer) { bRepo->saveToCSV(benutzer); }
		void saveToHTML(Benutzer* benutzer) { bRepo->saveToHTML(benutzer); }

		Benutzer* getBenutzerByIndex(int index) { return bRepo->getBenutzerByIndex(index); }
		std::vector<Benutzer*> getAllBenutzer() { return bRepo->getAllBenutzer(); }
};

#endif /* BENUTZERCONTROLLER_H */
