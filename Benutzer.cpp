/*
 * Benutzer.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: root
 */

#include "Benutzer.h"

#include <string>
#include <algorithm>

Benutzer::Benutzer(std::string vorname, std::string name) {
	this->name = name;
	this->vorname = vorname;
}

std::string Benutzer::getName() {
	return this->name;
}

std::string Benutzer::getVorname() {
	return this->vorname;
}

std::vector<Film*> Benutzer::getWatchList() {
	return this->watchlist;
}

void Benutzer::addFilm(Film* f) {
	this->watchlist.push_back(f);
}

void Benutzer::removeFilm(Film* f) {
	this->watchlist.erase(find_if(this->watchlist.begin(), this->watchlist.end(), [f](Film* film) { return f->getTitel() == film->getTitel() and f->getErscheinungsjahr() == film->getErscheinungsjahr(); }));
}

bool Benutzer::isOnWatchList(Film* f) {
	return std::find_if(this->watchlist.begin(), this->watchlist.end(), [f] (Film* film) { return f->getTitel() == film->getTitel() and f->getErscheinungsjahr() == film->getErscheinungsjahr(); }) != this->watchlist.end();
}
