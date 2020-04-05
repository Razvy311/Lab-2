/*
 * Medikament.h
 *
 *  Created on: Mar 29, 2020
 *      Author: root
 */

#ifndef MEDIKAMENT_H_
#define MEDIKAMENT_H_

#include <string>

class Medikament {
	private:
		std::string name;

		int menge;

		double preis;
		double konzentration;
	public:
		Medikament(std::string name, double konzentration, double preis, int menge);

		void setName(std::string name);
		void setMenge(int menge);
		void setPreis(double preis);
		void setKonzentration(double konzentration);

		std::string getName();
		int getMenge();
		double getPreis();
		double getKonzenration();

		std::string toString();
};

#endif /* MEDIKAMENT_H_ */
