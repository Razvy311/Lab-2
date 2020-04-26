/*
 * BenutzerRepository.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: root
 */

#include <iostream>
#include <algorithm>

#include "BenutzerRepository.h"

BenutzerRepository::BenutzerRepository() {
	// Initial 10 users.
	this->benutzer.push_back(new Benutzer("Marsha", "Pittman"));
	this->benutzer.push_back(new Benutzer("Marianne", "Greer"));
	this->benutzer.push_back(new Benutzer("Leslie", "Jackson"));
	this->benutzer.push_back(new Benutzer("Daisy", "Fowler"));
	this->benutzer.push_back(new Benutzer("Robyn", "Hale"));
	this->benutzer.push_back(new Benutzer("Dean", "Allison"));
	this->benutzer.push_back(new Benutzer("Clint", "Woods"));
	this->benutzer.push_back(new Benutzer("Rodolfo", "Mccormick"));
	this->benutzer.push_back(new Benutzer("Peggy", "Carr"));
	this->benutzer.push_back(new Benutzer("Amy", "Palmer"));
}

BenutzerRepository::~BenutzerRepository() {
	for(Benutzer* b : this->benutzer)
		delete b;
}

void BenutzerRepository::addUser(std::string vorname, std::string name) {
	if(find_if(this->benutzer.begin(), this->benutzer.end(), [vorname, name](Benutzer* b) { return b->getVorname() == vorname and b->getName() == name; }) == this->benutzer.end()) {
		this->benutzer.push_back(new Benutzer(vorname, name));
		std::cout << "Benutzer wurde erfolgreich hinzugefugt!" << std::endl;
	} else
		std::cout << "Benutzer existier schon!" << std::endl;
}

void BenutzerRepository::removeUser(std::string vorname, std::string name) {
	auto match = find_if(this->benutzer.begin(), this->benutzer.end(), [vorname, name](Benutzer* b) { return b->getVorname() == vorname and b->getName() == name; });

	if(match == this->benutzer.end())
		std::cout << "Benutzer existiert nicht!" << std::endl;
	else {
		this->benutzer.erase(match);
		std::cout << "Benutzer wurde erfolgreich geloscht!" << std::endl;
	}
}

Benutzer* BenutzerRepository::getBenutzerByIndex(int index) {
	return this->benutzer[index];
}

std::vector<Benutzer*> BenutzerRepository::getAllBenutzer() {
	return this->benutzer;
}
