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
		void removeMedikament(std::string name);

		void modifyMedikament(std::string name, std::string newName);
		void modifyMedikamentM(std::string name, int menge);
		void modifyMedikamentP(std::string name, double preis);
		void modifyMedikamentK(std::string name, double konzentration);

		std::vector<Medikament*> getMedikamente();
};

#endif /* MEDIKAMENTREPOSITORY_H_ */
