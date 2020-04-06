/*
 * MedikamentRepository.cpp
 *
 *  Created on: Apr 4, 2020
 *      Author: root
 */

#include <utility>
#include <vector>
#include <string>
#include "MedikamentRepository.h"


void MedikamentRepository::addMedikament(Medikament medikament) {
	// If already exists, return.
	for(auto & m : this->medikamente)
		if( m.getName() == medikament.getName() && m.getKonzenration() == medikament.getKonzenration()) {
			m.setMenge(medikament.getMenge());
			return;
		}

	// Push it to the end.
	this->medikamente.push_back(medikament);
}

void MedikamentRepository::removeMedikament(std::string name, double konzentration) {
	for(auto m = this->medikamente.begin(); m != this->medikamente.end(); ++m)
		if(m->getName() == name && m->getKonzenration() == konzentration) {
			this->medikamente.erase(m);
			return;
		}

}

void MedikamentRepository::modifyMedikament(std::string name, double konzentration, std::string newName) {
	if(name == newName)
		return;

	for(auto & m : this->medikamente) {
		if(m.getName() == name && m.getKonzenration() == konzentration) {
			m.setName(newName);
			return;
		}
	}

}

void MedikamentRepository::modifyMedikamentM(std::string name, double konzentration, int menge) {
	for(auto & m : this->medikamente)
		if(m.getName() == name && m.getKonzenration() == konzentration) {
			m.setMenge(menge);
			return;
		}
}

void MedikamentRepository::modifyMedikamentP(std::string name, double konzentration, double preis) {
	for(auto & m : this->medikamente)
		if(m.getName() == name && m.getKonzenration() == konzentration) {
			m.setPreis(preis);
			return;
		}
}

void MedikamentRepository::modifyMedikamentK(std::string name, double konzentration, double newKonzentration) {
	if(konzentration == newKonzentration){
		return;
	}
	for(auto & m : this->medikamente)
		if(m.getName() == name && m.getKonzenration() == konzentration) {
			m.setKonzentration(newKonzentration);
			return;
		}
}

std::vector<Medikament> MedikamentRepository::getMedikamente() {
	return this->medikamente;
}

void MedikamentRepository::setMedikamente(std::vector<Medikament> newMeds){
	this->medikamente.clear();
	this->medikamente = std::move(newMeds);
}