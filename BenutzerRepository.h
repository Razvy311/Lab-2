/*
 * BenutzerRepository.h
 *
 *  Created on: Apr 26, 2020
 *      Author: root
 */

#ifndef BENUTZERREPOSITORY_H
#define BENUTZERREPOSITORY_H

#include "Benutzer.h"

class BenutzerRepository {
	private:
		std::vector<Benutzer*> benutzer;
	public:
		BenutzerRepository();
		~BenutzerRepository();

		void addUser(std::string vorname, std::string name);
		void removeUser(std::string vorname, std::string name);

		Benutzer* getBenutzerByIndex(int index);
		std::vector<Benutzer*> getAllBenutzer();
};

#endif /* BENUTZERREPOSITORY_H */
