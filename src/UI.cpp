/*
 * UI.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: root
 */

#if defined(_WIN32) or defined(_WIN64) or (defined(__CYGWIN__) and !defined(_WIN32))
	#define PLATFORM_NAME "windows"
#elif defined(__linux__)
	#define PLATFORM_NAME "linux"
#else
	#define PLATFORM_NAME NULL
#endif

#include <limits>
#include <iostream>
#include <string>
#include <vector>

#include "Benutzer.h"
#include "tests.h"

#include "FilmRepository.h"
#include "AdminController.h"
#include "BenutzerController.h"

using namespace std;

const char *get_platform_name() {
	return (PLATFORM_NAME == NULL) ? "" : PLATFORM_NAME;
}

void openCsv(std::string path) {
	if(get_platform_name() == "linux") // You need libreoffice 6.3 installed.
		system(("libreoffice6.3 --calc " + path).c_str());
	else if(get_platform_name() == "windows")
		system(("start excel " + path).c_str());
	else
		cout << "Unsupported operating system!";
}

void openHtml(std::string path) {
	if(get_platform_name() == "linux")
		system(("firefox " + path).c_str());
	else if(get_platform_name() == "windows")
		system(("explorer" + path).c_str());
	else
		cout << "Unsupported operating system!";
}

void displayAdmin(AdminController* aController) {
    cout<<"Sie arbeiten als Admin."<<'\n';
    while(true){
        cout<<"Optionen:"<<'\n';
        cout<<"     0. Zuruck."<<'\n';
        cout<<"     1. Add a movie."<<'\n';
        cout<<"     2. Delete a movie."<<'\n';
        cout<<"     3. Update."<<'\n';
        cout<<"     4. Show films."<<'\n';

        cout<<'\n'<<"Ihre Wahl: ";
        int wahl;
        cin>>wahl;

        cout<<'\n';

        if(wahl == 0){
            return;
        }
        if(wahl == 1){
            string titel, genre, link;
            int jahr, likes;

            while(true){
                cout<<"Introduce data for the movie."<<'\n'<<'\n';
                cout<<"Titel: ";
                cin>>titel;
                cout<<'\n';

                cout<<"Genre: ";
                cin>>genre;
                cout<<'\n';

                cout<<"Jahr: ";
                cin>>jahr;
                cout<<'\n';

                cout<<"Likes: ";
                cin>>likes;
                cout<<'\n';

                cout<<"Link: ";
                cin>>link;
                cout<<'\n';

                try {
                    aController->addFilm(titel, genre, jahr, likes, link);
                    break;
                }
                catch (FilmRepoException & r){
                    cout<<r.what()<<'\n';
                }
                catch (FilmValidatorException & v){
                    cout<<v.what()<<'\n';
                }
            }

            cout<<"The film was successfully added!";
            continue;
        }
        if(wahl == 2){
            string title;
            int year;

            while(true){
                cout<<"Introduce the title and the year of the movie to be removed."<<'\n'<<'\n';

                cout<<"Title: ";
                cin>>title;
                cout<<'\n';

                cout<<"Year: ";
                cin>>year;
                cout<<'\n';

                try{
                    aController->deleteFilm(title, year);
                    break;
                }
                catch (FilmRepoException & r){
                    cout<<r.what()<<'\n';
                }
                catch (FilmValidatorException & v){
                    cout<<v.what()<<'\n';
                }
            }

            cout<<"The film was successfully deleted!";
            continue;
        }

        if(wahl == 3){
            string title;
            int year, mod;

            cout<<"Choose an attribute to modify:"<<'\n';
            cout<<"     1. Title."<<'\n';
            cout<<"     2. Genre."<<'\n';
            cout<<"     3. Year."<<'\n';
            cout<<"     4. Likes."<<'\n';
            cout<<"     5. Link."<<'\n';
            cout<<'\n'<<"Write the number of your choice: ";
            cin>>mod;

            while (true) {
                cout << "Introduce the title and the year of the film to be modified." << '\n' << '\n';

                cout << "Title: ";
                cin >> title;
                cout << '\n';

                cout << "Year: ";
                cin >> year;
                cout << '\n';

                if(mod == 1){
                    string newT;
                    cout<<"New title: ";
                    cin>>newT;
                    cout<<'\n';

                    try{
                        aController->modifyTitel(title, year, newT);
                        break;
                    }
                    catch (FilmRepoException & r){
                        cout<<r.what()<<'\n';
                    }
                    catch (FilmValidatorException & v){
                        cout<<v.what()<<'\n';
                    }
                    continue;
                }

                if(mod == 2){
                    string newG;
                    cout<<"New genre: ";
                    cin>>newG;
                    cout<<'\n';

                    try{
                        aController->modifyGenre(title, year, newG);
                        break;
                    }
                    catch (FilmRepoException & r){
                        cout<<r.what()<<'\n';
                    }
                    catch (FilmValidatorException & v){
                        cout<<v.what()<<'\n';
                    }
                    continue;
                }

                if(mod == 3){
                    int newY;
                    cout<<"New year: ";
                    cin>>newY;
                    cout<<'\n';

                    try{
                        aController->modifyYear(title, year, newY);
                        break;
                    }
                    catch (FilmRepoException & r){
                        cout<<r.what()<<'\n';
                    }
                    catch (FilmValidatorException & v){
                        cout<<v.what()<<'\n';
                    }
                    continue;
                }

                if(mod == 4){
                    int newL;
                    cout<<"New number of likes: ";
                    cin>>newL;
                    cout<<'\n';

                    try{
                        aController->modifyLikes(title, year, newL);
                        break;
                    }
                    catch (FilmRepoException & r){
                        cout<<r.what()<<'\n';
                    }
                    catch (FilmValidatorException & v){
                        cout<<v.what()<<'\n';
                    }
                    continue;
                }

                if(mod == 5){
                    string newL;
                    cout<<"New link to trailer: ";
                    cin>>newL;
                    cout<<'\n';

                    try{
                        aController->modufyLink(title, year, newL);
                        break;
                    }
                    catch (FilmRepoException & r){
                        cout<<r.what()<<'\n';
                    }
                    catch (FilmValidatorException & v){
                        cout<<v.what()<<'\n';
                    }
                    continue;
                }
            }

            cout<<"The film was successfully updated!";
            continue;
        }
        if(wahl == 4){
            cout<<'\n'<<aController->showFilms()<<'\n';
        }
    }
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
		cout << "    3. Parse Watchliste to CSV" << endl;
		cout << "    4. Parse Watchliste to HTML" << endl;

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
			} case 3: {
				cout << "Die WatchListe wird zu einem CSV-format umgewandelt!" << endl;
				bController->saveToCSV(benutzer);

				openCsv("Watchlists/CSV/Watchlist-" + benutzer->getVorname() + "-" + benutzer->getName() + ".csv");

				goto Label;
			} case 4: {
				cout << "Die WatchListe wird zu einem HTML-format umgewandelt!" << endl;
				bController->saveToHTML(benutzer);

				openHtml("Watchlists/HTML/Watchlist-" + benutzer->getVorname() + "-" + benutzer->getName() + ".html");

				goto Label;
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
    tests();
    cout << endl;

    try {
        FilmRepository *fRepo = new FilmRepository();

        AdminController *aController = new AdminController(fRepo);
        BenutzerController *bController = new BenutzerController(fRepo);

        displayMainMenu(aController, bController);

        delete bController;
        delete aController;

    }
    catch (DatabaseException & d) {
        cout<<d.what();
    }


	return 0;
}
