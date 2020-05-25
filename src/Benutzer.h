/*
 * Benutzer.h
 *
 *  Created on: Apr 26, 2020
 *      Author: root
 */

#ifndef BENUTZER_H
#define BENUTZER_H

#include <vector>
#include <string>

#include "Film.h"

class Benutzer {
	private:
		std::string name;
		std::string vorname;

		std::vector<Film*> watchlist;
	public:
		// Constructor
		Benutzer(std::string vorname, std::string name);

		// Getters.
		std::string getName();
		std::string getVorname();

		std::vector<Film*> getWatchList();

		// WatchList Utilities.
		void addFilm(Film* f);
		void removeFilm(Film* f);

		bool isOnWatchList(Film* f);
};

#endif /* BENUTZER_H */
