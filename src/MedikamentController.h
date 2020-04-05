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

class MedikamentController {
	private:
		MedikamentRepository * repository;
	public:
		MedikamentController();
		~MedikamentController();

		std::vector<std::string> filterByName(std::string substring);
		std::vector<std::string> filterByMenge(int menge);

		std::vector<std::string> groupByPreis();

		// Repository functions.
		void addMedikament(Medikament* medikament);
		void removeMedikament(std::string name);

		void modifyMedikament(std::string name, std::string newName);
		void modifyMedikamentM(std::string name, int menge);
		void modifyMedikamentP(std::string name, double preis);
		void modifyMedikamentK(std::string name, double konzentration);

		MedikamentRepository * getRepository();
};

#endif /* MEDIKAMENTCONTROLLER_H_ */
