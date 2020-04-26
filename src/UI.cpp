/*
 * UI.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: root
 */

#include <iostream>
#include <string>
#include <vector>

#include "Benutzer.h"

using namespace std;

#include "FilmRepository.h"
#include "AdminController.h"
#include "BenutzerController.h"

void displayAdmin(AdminController* aController) {

}

void displayBenutzerEdit(BenutzerController* bController) {
	Label:
		cout << endl;
		cout << "Benutzer Bearbeiten:" << endl;
		cout << "    0. Zuruck" << endl;
		cout << "    1. Hinzufugen" << endl;
		cout << "    2. Loschen" << endl;

		cout << endl;
		cout << "Ihre Wahl: ";

		int id;
		cin >> id;

		switch(id) {
			case 0:
				cout << endl;
				return;
			case 1: {
				string vorname, name;

				cout << "Geben sie den vornamen ein: "; cin >> vorname;
				cout << "Geben sie den name ein: "; cin >> name;

				bController->addUser(vorname, name);
				goto Label;
			} case 2: {
				string vorname, name;

				cout << "Geben sie den vornamen ein: "; cin >> vorname;
				cout << "Geben sie den name ein: "; cin >> name;

				bController->removeUser(vorname, name);
				goto Label;
			} default:
				cout << "Ungultige wahl!" << endl << endl;
				goto Label;
		}
}

void displayFilmAuswahl(BenutzerController* bController, Benutzer* benutzer) {
	Label:
		cout << endl;
		cout << "Filmauswahl:" << endl;
		cout << "    0. Exit" << endl;
		cout << "    1. Film Explorer" << endl;
		cout << "    2. Meine Watchliste" << endl;

		cout << endl;
		cout << "Ihre Wahl: ";

		int id;
		cin >> id;

		switch(id) {
			case 0:
				cout << endl;
				return;
			case 1: {
				string genre;

				cout << endl;
				cout << "Geben sie genre an die sie bevorzugen: ";

				cin.ignore( numeric_limits<streamsize>::max(), '\n' );
				getline(cin, genre);

				std::vector<Film*> filme = bController->filterByGenre(genre);

				if(filme.size() == 0) {
					cout << "Keine Filme wurden gefunden!" << endl;
					goto Label;
				}

				Film_Loop:
					bool breakOut = true;

					for(Film* film : filme)
						if(!benutzer->isOnWatchList(film)) {
							breakOut = false;

							cout << endl << endl;
							cout << "Titel: " << film->getTitel() << endl;
							cout << "Genre: " << film->getGenre() << endl;
							cout << "Erscheinungsjahr: " << film->getErscheinungsjahr() << endl;
							cout << "Likes: " << film->getAnzahlLikes() << endl;
							cout << "Trailer: " << film->getLinkTrailer() << endl;
							cout << endl;
							cout << "0-Verlassen  1-Hinzufugen  2-Weiter" << endl;
							cout << endl;

							Wahl_Label:
								cout << "Ihre Wahl: ";

								int op;
								cin >> op;
								switch(op) {
									case 0:
										goto Label;
									case 1:
										benutzer->addFilm(film);
										cout << "Film wurder zur Watchliste hinzugefugt." << endl;
										break;
									case 2:
										break;
									default:
										cout << "Ungultige Wahl!" << endl;
										goto Wahl_Label;
								}
						}

					if(breakOut)
						goto Label;
					goto Film_Loop;
			} case 2: {
				cout << "Watchliste:" << endl;
				for(unsigned int i = 0; i < benutzer->getWatchList().size(); i++)
					cout << "    " << i << ". " << benutzer->getWatchList()[i]->showFilm() << endl;

				cout << endl;
				cout << "-1-Zuruck  ID-The Film to Remove" << endl;

				Label_WatchListe:
					cout << endl;
					cout << "Ihre Wahl: ";

					int option;
					cin >> option;

					if(option == -1)
						goto Label;
					else if(option >= 0 && option < benutzer->getWatchList().size()) {
						bool like;
						string wahl;
						Label_Like:
							cout << "Mochtests tu diesen Film bewerten?" << endl;
							cout << "Wahl (Ja/Nein): "; cin >> wahl;

							if(wahl == "ja")
								like = true;
							else if(wahl == "nein")
								like = false;
							else {
								cout << "Ungultige Wahl!" << endl;
								goto Label_Like;
							}

							bController->removeFilmFromWatchlist(benutzer, benutzer->getWatchList()[option], like);
							goto Label_WatchListe;
					} else {
						cout << "Ungultige Wahl!" << endl;
						goto Label_WatchListe;
					}
			} default:
				cout << "Ungultige wahl!" << endl << endl;
				goto Label;
		}
}

void displayBenutzer(BenutzerController* bController) {
	Label:
		cout << endl;
		cout << "Benutzer Menu:" << endl;
		cout << "Benutzer: " << endl;
		for(unsigned int i = 0; i < bController->getAllBenutzer().size(); i++)
			cout << "    " << i << ". " << bController->getBenutzerByIndex(i)->getVorname() << " " << bController->getBenutzerByIndex(i)->getName() << endl;
		cout << "    " << bController->getAllBenutzer().size() << ". Benutzer bearbeiten" << endl;

		int id;

		cout << endl;
		cout << "Wahlen sie eine Benutzer aus oder -1 um zuruck zu gehen: ";
		cin >> id;

		if(id == -1) {
			cout << endl;
			return;
		} else if(id == bController->getAllBenutzer().size()){
			displayBenutzerEdit(bController);
			goto Label;
		} else if(id < 0 or id >= bController->getAllBenutzer().size()) {
			cout << "ID ist ungultig, bitte geben sie eine neue ein!" << endl << endl;
			goto Label;
		}

		Benutzer* benutzer = bController->getBenutzerByIndex(id);
		displayFilmAuswahl(bController, benutzer);
		goto Label;
}

void displayMainMenu(AdminController* aController, BenutzerController* bController) {
	Label:
		cout << "Willkommen ins Kino." << endl;
		cout << "    0. Exit" << endl;
		cout << "    1. Admin" << endl;
		cout << "    2. Benutzer" << endl;
		cout << endl;

		int op;

		cout << "Ihre Wahl: ";
		cin >> op;

		switch(op) {
			case 0:
				cout << "Bye Bye!" << endl;
				return;
			case 1:
				displayAdmin(aController);
				goto Label;
			case 2:
				displayBenutzer(bController);
				goto Label;
			default:
				cout << "Sie haven eine ungultige Option eingegeben!" << endl;
				cout << endl;
				goto Label;
		}
}

int main() {
	FilmRepository * fRepo = new FilmRepository();

	AdminController * aController = new AdminController(fRepo);
	BenutzerController * bController = new BenutzerController(fRepo);

	displayMainMenu(aController, bController);

	delete aController;
	delete bController;

	return 0;
}
