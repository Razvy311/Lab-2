/*
 * MedikamentRepository.cpp
 *
 *  Created on: Apr 4, 2020
 *      Author: root
 */

#include <vector>
#include <string>
#include "MedikamentRepository.h"

MedikamentRepository::~MedikamentRepository() {
	for(auto m = this->medikamente.begin(); m != this->medikamente.end(); ++m)
		delete (*m);
}

void MedikamentRepository::addMedikament(Medikament* medikament) {
	// If already exists, return.
	for(auto m = this->medikamente.begin(); m != this->medikamente.end(); ++m)
		if((*m)->getName() == medikament->getName()) {
			(*m)->setMenge(medikament->getMenge());
			return;
		}

	// Push it to the end.
	this->medikamente.push_back(medikament);
}

void MedikamentRepository::removeMedikament(std::string name) {
	for(auto m = this->medikamente.begin(); m != this->medikamente.end(); ++m)
		if((*m)->getName() == name)
			this->medikamente.erase(m);
}

void MedikamentRepository::modifyMedikament(std::string name, std::string newName) {
	if(name == newName)
		return;

	for(auto m = this->medikamente.begin(); m != this->medikamente.end(); ++m)
		if((*m)->getName() == name) {
			(*m)->setName(newName);
			return;
		}
}

void MedikamentRepository::modifyMedikamentM(std::string name, int menge) {
	for(auto m = this->medikamente.begin(); m != this->medikamente.end(); ++m)
		if((*m)->getName() == name) {
			(*m)->setMenge(menge);
			return;
		}
}

void MedikamentRepository::modifyMedikamentP(std::string name, double preis) {
	for(auto m = this->medikamente.begin(); m != this->medikamente.end(); ++m)
		if((*m)->getName() == name) {
			(*m)->setPreis(preis);
			return;
		}
}

void MedikamentRepository::modifyMedikamentK(std::string name, double konzentration) {
	for(auto m = this->medikamente.begin(); m != this->medikamente.end(); ++m)
		if((*m)->getName() == name) {
			(*m)->setKonzentration(konzentration);
			return;
		}
}

std::vector<Medikament*> MedikamentRepository::getMedikamente() {
	return this->medikamente;
}
