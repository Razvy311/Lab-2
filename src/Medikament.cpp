/*
 * Medikament.cpp
 *
 *  Created on: Mar 29, 2020
 *      Author: root
 */

#include <string>
#include "Medikament.h"

// ------ Constructor ----------------------------------------

/**
 * Constructs a new instance of a medicine.
 *
 * @param name
 *            - the name of the medicine.
 * @param konzentration
 *            - the concentration of the medicine.
 */
Medikament::Medikament(std::string name, double konzentration, double preis, int menge) {
	this->name = name;
	this->menge = menge;
	this->preis = preis;
	this->konzentration = konzentration;
}

// ------ Utilities ------------------------------------------

std::string Medikament::toString() {
	return this->name + "(konz=" + std::to_string(this->konzentration) + "%, menge=" + std::to_string(menge) + ", preis=" + std::to_string(preis) + "$)";
}

// ------ Getters & Setters ----------------------------------

void Medikament::setName(std::string name) {
	this->name = name;
}

void Medikament::setMenge(int menge) {
	this->menge = menge;
}

void Medikament::setPreis(double preis) {
	this->preis = preis;
}

void Medikament::setKonzentration(double konzentration) {
	this->konzentration = konzentration;
}

int Medikament::getMenge() {
	return this->menge;
}

double Medikament::getPreis() {
	return this->preis;
}

double Medikament::getKonzenration() {
	return this->konzentration;
}

std::string Medikament::getName() {
	return this->name;
}

