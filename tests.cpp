//
// Created by Nikos on 4/27/2020.
//
#include "AdminController.h"
#include "BenutzerController.h"
#include <assert.h>
#include "tests.h"

void testAddFilm(){
    FilmRepository * fRepo = new FilmRepository();

    AdminController * aController = new AdminController(fRepo);

    for(int an = 2001; an < 2005; an++) {
        aController->addFilm("film11", "c", an, 23, "l");
        assert(aController->showFilms().find(Film("film11", "c", an, 23, "l").showFilm()) != std::string::npos);
    }
}

void testDeleteFilm(){
    FilmRepository * fRepo = new FilmRepository();

    AdminController * aController = new AdminController(fRepo);

    for(int an = 2001; an < 2005; an++) {
        aController->addFilm("film11", "c", an, 23, "l");
        assert(aController->showFilms().find(Film("film11", "c", an, 23, "l").showFilm()) != std::string::npos);
    }

    for(int an = 2001; an < 2005; an++) {
        aController->deleteFilm("film11", an);
        assert(aController->showFilms().find(Film("film11", "c", an, 23, "l").showFilm()) == std::string::npos);
    }
}

void testUpdate(){
    FilmRepository * fRepo = new FilmRepository();

    AdminController * aController = new AdminController(fRepo);

    for(int an = 2001; an < 2005; an++) {
        aController->addFilm("film11", "c", an, 23, "l");
        assert(aController->showFilms().find(Film("film11", "c", an, 23, "l").showFilm()) != std::string::npos);
    }

    for(int an = 2001; an < 2005; an++) {
        aController->modifyTitel("film11", an, "film12");
        assert(aController->showFilms().find(Film("film12", "c", an, 23, "l").showFilm()) != std::string::npos);
    }

}

void testAddUser(){
    FilmRepository * fRepo = new FilmRepository();

    BenutzerController * bController = new BenutzerController(fRepo);

    bController->addUser("ana", "maria");
    assert(bController->getBenutzerByIndex(10)->getName() == "maria" && bController->getBenutzerByIndex(10)->getVorname() == "ana");
}

void testDeleteUser(){
    FilmRepository * fRepo = new FilmRepository();

    BenutzerController * bController = new BenutzerController(fRepo);

    bController->addUser("ana", "maria");
    assert(bController->getBenutzerByIndex(10)->getName() == "maria" && bController->getBenutzerByIndex(10)->getVorname() == "ana");
    assert(bController->getAllBenutzer().size() == 11);

    bController->removeUser("ana", "maria");
    assert(bController->getAllBenutzer().size() == 10);
}

void tests(){
    // Test admin controller.
    testAddFilm();
    testDeleteFilm();
    testUpdate();

    // Test user controller.
    testAddUser();
    testDeleteUser();
}