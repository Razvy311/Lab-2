/*
 * MedikamentController.cpp
 *
 *  Created on: Apr 4, 2020
 *      Author: root
 */

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include "MedikamentRepository.h"
#include "MedikamentController.h"

MedikamentController::MedikamentController() {
	this->repository = new MedikamentRepository();
	this->undo_redo = new Undo_Redo();
}

MedikamentController::~MedikamentController() {
	delete this->repository;
	delete this->undo_redo;
}

void MedikamentController::addMedikament(Medikament* medikament) {
	this->repository->addMedikament(medikament);
	this->undo_redo->flag = false;
	this->undo_redo->setIndex(this->undo_redo->getIndex() + 1);
	this->undo_redo->addStep(this->repository->getMedikamente());
}

void MedikamentController::removeMedikament(std::string name, double konzentration) {
	this->repository->removeMedikament(name, konzentration);
	this->undo_redo->flag = false;
	this->undo_redo->setIndex(this->undo_redo->getIndex() + 1);
	this->undo_redo->addStep(this->repository->getMedikamente());
}

void MedikamentController::modifyMedikament(std::string name, double konzentration, std::string newName) {
	this->repository->modifyMedikament(name, konzentration, newName);
	this->undo_redo->flag = false;
	this->undo_redo->setIndex(this->undo_redo->getIndex() + 1);
	this->undo_redo->addStep(this->repository->getMedikamente());
}

void MedikamentController::modifyMedikamentM(std::string name, double konzentration, int menge) {
	this->repository->modifyMedikamentM(name, konzentration, menge);
	this->undo_redo->flag = false;
	this->undo_redo->setIndex(this->undo_redo->getIndex() + 1);
	this->undo_redo->addStep(this->repository->getMedikamente());
}

void MedikamentController::modifyMedikamentP(std::string name, double konzentration, double preis) {
	this->repository->modifyMedikamentP(name, konzentration, preis);
	this->undo_redo->flag = false;
	this->undo_redo->setIndex(this->undo_redo->getIndex() + 1);
	this->undo_redo->addStep(this->repository->getMedikamente());
}

void MedikamentController::modifyMedikamentK(std::string name, double konzentration, double newKonzentration) {
	this->repository->modifyMedikamentK(name, konzentration, newKonzentration);
	this->undo_redo->flag = false;
	this->undo_redo->setIndex(this->undo_redo->getIndex() + 1);
	this->undo_redo->addStep(this->repository->getMedikamente());
}

std::vector<std::string> MedikamentController::groupByPreis() {
	// Get all the medicaments and sort them after the price.
	std::vector<Medikament*> medVector;
	for(Medikament * m : this->repository->getMedikamente())
		medVector.push_back(m);

	std::sort(medVector.begin(), medVector.end(), [] (Medikament* m1, Medikament* m2) {
		return m1->getPreis() < m2->getPreis();
	});

	// Make the groups.
	// Each group is separated by an empty line.
	std::vector<std::string> result;

	double currentPreis = medVector[0]->getPreis();
	result.push_back(medVector[0]->toString());

	for(unsigned int i = 1; i < medVector.size(); ++i) {
		if(currentPreis != medVector[i]->getPreis()) {
			result.push_back(" ");
			currentPreis = medVector[i]->getPreis();
		}

		result.push_back(medVector[i]->toString());
	}

	return result;
}

std::vector<std::string> MedikamentController::filterByName(std::string substring) {
	std::vector<std::string> result;
	for(Medikament * m : this->repository->getMedikamente())
		if(m->getName().find(substring) != -1)
			result.push_back(m->toString());

	std::sort(result.begin(), result.end());
	return result;
}

std::vector<std::string> MedikamentController::filterByMenge(int menge) {
	std::vector<std::string> result;
	for(Medikament * m : this->repository->getMedikamente())
		if(m->getMenge() < menge)
			result.push_back(m->toString());

	std::sort(result.begin(), result.end());
	return result;
}

MedikamentRepository * MedikamentController::getRepository() {
	return this->repository;
}

void MedikamentController::callUndo(){
	this->repository->setMedikamente(this->undo_redo->undo());
}

void MedikamentController::callRedo(){
	this->repository->setMedikamente(this->undo_redo->redo());
}