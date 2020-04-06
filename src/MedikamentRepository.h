/*
 * MedikamentRepository.h
 *
 *  Created on: Apr 4, 2020
 *      Author: root
 */

#ifndef MEDIKAMENTREPOSITORY_H_
#define MEDIKAMENTREPOSITORY_H_

#include <vector>
#include <string>
#include "Medikament.h"

class MedikamentRepository {
	private:
		std::vector<Medikament*> medikamente;
	public:
		~MedikamentRepository();

		void addMedikament(Medikament* medikament);
		void removeMedikament(std::string name, double konzentration);

		void modifyMedikament(std::string name, double konzentration,  std::string newName);
		void modifyMedikamentM(std::string name, double konzentration, int menge);
		void modifyMedikamentP(std::string name, double konzentration, double preis);
		void modifyMedikamentK(std::string name, double konzentration, double newKonzentration);

		std::vector<Medikament*> getMedikamente();
		void setMedikamente(std::vector<Medikament *> newMeds);
};

#endif /* MEDIKAMENTREPOSITORY_H_ */
