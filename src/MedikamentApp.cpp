/*
 * MedikamentApp.cpp
 *
 *  Created on: Mar 29, 2020
 *      Author: root
 */

#include <string>
#include <assert.h>
#include <iostream>
#include "Medikament.h"
#include "MedikamentController.h"

using namespace std;

int main() {

	// Create the central repository.
	MedikamentController * controller = new MedikamentController();

	controller->addMedikament(new Medikament("Name1", 90.2, 12.5, 3));
	controller->addMedikament(new Medikament("Name3", 12.2, 4.3, 7));
	controller->addMedikament(new Medikament("Name3", 17.9, 107, 20));
	controller->addMedikament(new Medikament("Name4", 7.8, 235.99, 100));
	controller->addMedikament(new Medikament("Name2", 82.2, 44.2, 2));

	// Check if the vector is created right.
	assert(controller->getRepository()->getMedikamente().size() == 4);

	cout << "Medikamente: " << endl;
	for(Medikament * m : controller->getRepository()->getMedikamente())
		cout << "   " << m->toString() << endl;

	// Test the remove function.
	controller->getRepository()->removeMedikament("Name3");

	assert(controller->getRepository()->getMedikamente().size() == 3);
	for(Medikament * m : controller->getRepository()->getMedikamente())
		assert(m->getName() != "Name3");

	// Test modification functions.
	controller->getRepository()->modifyMedikament("Name4", "Name3");
	assert(controller->getRepository()->getMedikamente().size() == 3);
	for(Medikament * m : controller->getRepository()->getMedikamente())
		assert(m->getName() != "Name4");

	controller->getRepository()->modifyMedikamentK("Name1", 9.0);
	assert(controller->getRepository()->getMedikamente().size() == 3);
	for(Medikament * m : controller->getRepository()->getMedikamente())
		assert(m->getKonzenration() != 90.2);

	controller->getRepository()->modifyMedikamentP("Name3", 44.2);
	assert(controller->getRepository()->getMedikamente().size() == 3);
	for(Medikament * m : controller->getRepository()->getMedikamente())
		assert(m->getPreis() != 4.3);

	controller->getRepository()->modifyMedikamentM("Name1", 18);
	assert(controller->getRepository()->getMedikamente().size() == 3);
	for(Medikament * m : controller->getRepository()->getMedikamente())
		assert(m->getMenge() != 3);
	// Repository working correctly if we got to this point.

	cout << endl;

	// Filter test
	vector<string> firstList = controller->filterByName("Name");
	vector<string> secondList = controller->filterByName("e1");

	assert(firstList.size() == 3);
	assert(secondList.size() == 1);

	cout << "FirstFilter (Name): " << endl;
	for(string s : firstList)
		cout << "    " << s << endl;
	cout << "SecondFilter (Name): " << endl;
	for(string s : secondList)
		cout << "    " << s << endl;
	cout << endl;

	// Menge filter
	vector<string> thirdList = controller->filterByMenge(4);
	assert(thirdList.size() == 1);

	cout << "ThirdFilter (Menge): " << endl;
	for(string s : thirdList)
		cout << "    " << s << endl;
	cout << endl;

	// Groups.
	vector<string> groups = controller->groupByPreis();

	cout << "Groups: " << endl;
	for(string s : groups)
		cout << "    " << s << endl;

	cout << endl << "TEST DONE!" << endl;

	delete controller;
}
