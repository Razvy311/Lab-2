/*
 * BenutzerRepository.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: root
 */

#include <fstream>
#include <iostream>
#include <algorithm>

#include "BenutzerRepository.h"

/** Constructs a new repository for the Users. */
BenutzerRepository::BenutzerRepository(FilmRepository* repo) {
	this->filmRepo = repo;
	readDatabase();
}

/** The destructor of this Repository. */
BenutzerRepository::~BenutzerRepository() {
	writeDatabase();

	for(Benutzer* b : this->benutzer)
		delete b;
}

/**
 * Adds a new user to this repository.
 *
 * @param vorname
 *            - the surname of the user.
 * @param name
 *            - the name of the user.
 */
void BenutzerRepository::addUser(std::string vorname, std::string name) {
	if(find_if(this->benutzer.begin(), this->benutzer.end(), [vorname, name](Benutzer* b) { return b->getVorname() == vorname and b->getName() == name; }) == this->benutzer.end()) {
		this->benutzer.push_back(new Benutzer(vorname, name));
		std::cout << "Benutzer wurde erfolgreich hinzugefugt!" << std::endl;
	} else
	    throw BenutzerRepoException("The user already exists!");
}

/**
 * Removes a user from this repository.
 *
 * @param vorname
 *            - the surname of the user.
 * @param name
 *            - the name of the user.
 */
void BenutzerRepository::removeUser(std::string vorname, std::string name) {
	auto match = find_if(this->benutzer.begin(), this->benutzer.end(), [vorname, name](Benutzer* b) { return b->getVorname() == vorname and b->getName() == name; });

	if(match == this->benutzer.end())
        throw BenutzerRepoException("The user was not found!");
	else {
		this->benutzer.erase(match);
		std::cout << "Benutzer wurde erfolgreich geloscht!" << std::endl;
	}
}

/**
 * Returns a pointer of an User based on its index in the vector.
 *
 * @return A pointer of an User base on its index in the vector.
 */
Benutzer* BenutzerRepository::getBenutzerByIndex(int index) {
	return this->benutzer[index];
}

/**
 * Returns a vector containing pointers for every created User.
 *
 * @return A vector containing pointers for every created User.
 */
std::vector<Benutzer*> BenutzerRepository::getAllBenutzer() {
	return this->benutzer;
}

// CSV - HTML

/**
 * Writes a player's watchlist to a CSV file.
 *
 * @param benutzer
 *            - a pointer to the user to use.
 */
void BenutzerRepository::saveToCSV(Benutzer* benutzer) {
	std::ofstream output("Watchlists/CSV/Watchlist-" + benutzer->getVorname() + "-" + benutzer->getName() + ".csv", std::ofstream::trunc);
	if(output.is_open()) {
		for(Film* f : benutzer->getWatchList())
			output << f->getTitel() << "," << f->getGenre() << "," << f->getErscheinungsjahr() << "," << f->getAnzahlLikes() << "," << f->getLinkTrailer() << std::endl;

		output.flush();
		output.close();
	} else
	    throw DatabaseException("Unable to open the watchlist csv for this user!");
}

/**
 * Writes a player's watchlist to a CSV file.
 *
 * @param benutzer
 *            - a pointer to the user to use.
 */
void BenutzerRepository::saveToHTML(Benutzer* benutzer) {
	std::ofstream output("Watchlists/HTML/Watchlist-" + benutzer->getVorname() + "-" + benutzer->getName() + ".html", std::ofstream::trunc);
	if(output.is_open()) {
		// Default html type tags.
		output << "<!DOCTYPE html>" << std::endl;
		output << "<html>" << std::endl;

		// Header.
		output << "\t<head>" << std::endl;
		output << "\t\t<title>" << "WatchList of " << benutzer->getVorname() << " " << benutzer->getName() << "</title>" << std::endl;
		output << "\t</head>" << std::endl;

		output << std::endl;

		// Body
		output << "\t<body>" << std::endl;
		output << "\t\t<table border=\"1\">" << std::endl;

		// Column Names.
		output << "\t\t\t<tr>" << std::endl;
		output << "\t\t\t\t<td>Titel</td>" << std::endl;
		output << "\t\t\t\t<td>Genre</td>" << std::endl;
		output << "\t\t\t\t<td>Jahr</td>" << std::endl;
		output << "\t\t\t\t<td>Likes</td>" << std::endl;
		output << "\t\t\t\t<td>Trailer Link</td>" << std::endl;
		output << "\t\t\t</tr>" << std::endl;

		// Table input.
		for(Film* f : benutzer->getWatchList()) {
			output << "\t\t\t<tr>" << std::endl;
			output << "\t\t\t\t<td>" << f->getTitel() << "</td>" << std::endl;
			output << "\t\t\t\t<td>" << f->getGenre() << "</td>" << std::endl;
			output << "\t\t\t\t<td>" << f->getErscheinungsjahr() << "</td>" << std::endl;
			output << "\t\t\t\t<td>" << f->getAnzahlLikes() << "</td>" << std::endl;
			output << "\t\t\t\t<td><a href=\"https://" << f->getLinkTrailer() << "\">Trailer</a></td>" << std::endl;
			output << "\t\t\t</tr>" << std::endl;
		}

		output << "\t\t</table>" << std::endl;
		output << "\t</body>" << std::endl;

		output << "</html>" << std::endl;
	} else
        throw DatabaseException("Unable to open the watchlist html for this user!");
}

// ----- Abstract Methods --------------------

/** Read every user and his watchlist from a local file. */
void BenutzerRepository::readDatabase() {
	Benutzer* newBenutzer = nullptr;

	std::string toParse;
	std::string name;

	std::ifstream input("Benutzer.txt");
	if(input.is_open()) {
		while(true) {
			input >> toParse;
			if(input.eof())
				break;

			if(toParse.find("[") == std::string::npos) {
				if(newBenutzer != nullptr)
					this->benutzer.push_back(newBenutzer);

				// Read Benutzer.
				input >> name;
				newBenutzer = new Benutzer(toParse, name);
			} else
				newBenutzer->addFilm(this->filmRepo->getFilmBy(toParse.substr(1, toParse.find("-") - 1), std::stoi(toParse.substr(toParse.find("-") + 1, toParse.size() - 2))));
		}

		if(newBenutzer != nullptr)
			this->benutzer.push_back(newBenutzer);

		input.close();
	} else
		std::cout << "Unable to open BenutzerDatabase!";
}

/** Write every user and his watchlist to a local file. */
void BenutzerRepository::writeDatabase() {
	// The format of this will look a little weird.
	// Every user without any film in the watchlist will
	// have 2 empty lines after this name. The first one is reserved
	// for the watchlist and one is there because it looking better. :)

	std::ofstream output("Benutzer.txt", std::ofstream::trunc);
	if(output.is_open()) {
		// Write the new data.
		for(Benutzer* b : this->benutzer) {
			output << b->getVorname() << " " << b->getName() << std::endl;
			for(Film* f : b->getWatchList())
				output << "[" << f->getTitel() << "-" << std::to_string(f->getErscheinungsjahr()) << "] ";
			output << std::endl << std::endl;
		}

		output.flush();
		output.close();
	} else
        throw DatabaseException("Unable to open BenutzerDatabase!");
}
