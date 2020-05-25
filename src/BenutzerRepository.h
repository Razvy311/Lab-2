/*
 * BenutzerRepository.h
 *
 *  Created on: Apr 26, 2020
 *      Author: root
 */

#ifndef BENUTZERREPOSITORY_H
#define BENUTZERREPOSITORY_H

#include "Benutzer.h"
#include "IORepoAbstract.h"
#include "FilmRepository.h"

class BenutzerRepository : public IORepoAbstract {
	private:
		std::vector<Benutzer*> benutzer;

		FilmRepository* filmRepo;
	public:
		BenutzerRepository(FilmRepository* repo);
		~BenutzerRepository();

		void addUser(std::string vorname, std::string name);
		void removeUser(std::string vorname, std::string name);

		Benutzer* getBenutzerByIndex(int index);
		std::vector<Benutzer*> getAllBenutzer();

		// Format Saving
		void saveToCSV(Benutzer* benutzer);
		void saveToHTML(Benutzer* benutzer);

		// Abstract methods.
		void readDatabase();
		void writeDatabase();
};

#endif /* BENUTZERREPOSITORY_H */
