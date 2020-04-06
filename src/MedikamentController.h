/*
 * MedikamentController.h
 *
 *  Created on: Apr 4, 2020
 *      Author: root
 */

#ifndef MEDIKAMENTCONTROLLER_H_
#define MEDIKAMENTCONTROLLER_H_

#include <string>
#include <vector>
#include "Medikament.h"
#include "MedikamentRepository.h"
#include "undo_redo.h"
class Undo_Redo;

class MedikamentController {
	private:
		MedikamentRepository * repository;
		Undo_Redo * undo_redo;

	public:
		MedikamentController();
		~MedikamentController();

		std::vector<std::string> filterByName(std::string substring);
		std::vector<std::string> filterByMenge(int menge);

		std::vector<std::string> groupByPreis();

		// Repository functions.
		void addMedikament(Medikament medikament);
		void removeMedikament(std::string name, double konzentration);

		void modifyMedikament(std::string name, double konzentration, std::string newName);
		void modifyMedikamentM(std::string name, double konzentration, int menge);
		void modifyMedikamentP(std::string name, double konzentration, double preis);
		void modifyMedikamentK(std::string name, double konzentration, double newKonzentration);

		MedikamentRepository * getRepository();

		void callUndo();
		void callRedo();
};

#endif /* MEDIKAMENTCONTROLLER_H_ */
