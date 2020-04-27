/*
 * Benutzer.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: root
 */

#include "Benutzer.h"

#include <string>
#include <algorithm>

/**
 * Constructs a new User.
 *
 * @param vorname
 *            - the surname of the User.
 * @param name
 *            - the name of the User.
 */
Benutzer::Benutzer(std::string vorname, std::string name) {
	this->name = name;
	this->vorname = vorname;
}

/**
 * Returns the name of the user.
 *
 * @return The name of the user.
 */
std::string Benutzer::getName() {
	return this->name;
}

/**
 * Returns the surname of the user.
 *
 * @return The surname of the user.
 */
std::string Benutzer::getVorname() {
	return this->vorname;
}

/**
 * Returns the watchlist of this user.
 *
 * @return The watchlist of this user.
 */
std::vector<Film*> Benutzer::getWatchList() {
	return this->watchlist;
}

/**
 * Adds a new film to this watchlist.
 *
 * This method does not do any further testing, use
 * on your own risk.
 *
 * @param f
 *            - a pointer to a film to add.
 */
void Benutzer::addFilm(Film* f) {
	this->watchlist.push_back(f);
}

/**
 * Removes a film from this watchlist.
 *
 * If the method isn't present in the watchlist, this
 * method does nothing.
 *
 * @param f
 *            - a pointer to a film to remove.
 */
void Benutzer::removeFilm(Film* f) {
	this->watchlist.erase(find_if(this->watchlist.begin(), this->watchlist.end(), [f](Film* film) { return f->getTitel() == film->getTitel() and f->getErscheinungsjahr() == film->getErscheinungsjahr(); }));
}

/**
 * Checks if a film is on this watchlist.
 *
 * @param f
 *            - a pointer to the film to check.
 *
 * @return True if the film is on the watchlist, false otherwise.
 */
bool Benutzer::isOnWatchList(Film* f) {
	return std::find_if(this->watchlist.begin(), this->watchlist.end(), [f] (Film* film) { return f->getTitel() == film->getTitel() and f->getErscheinungsjahr() == film->getErscheinungsjahr(); }) != this->watchlist.end();
}
