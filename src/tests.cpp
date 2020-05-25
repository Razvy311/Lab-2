//
// Created by Nikos on 4/27/2020.
//
#include "AdminController.h"
#include "BenutzerController.h"
#include <assert.h>
#include "tests.h"

#include <iostream>

using namespace std;

void testAddFilm(){
    FilmRepository * fRepo = new FilmRepository();

    AdminController * aController = new AdminController(fRepo);

    for(int an = 2001; an < 2005; an++) {
        aController->addFilm("film11", "c", an, 23, "l");
        assert(aController->showFilms().find(Film("film11", "c", an, 23, "l").showFilm()) != std::string::npos);
    }
    for(int an = -1; an < 3; an++) {
        try {
            aController->addFilm("film11", "c", an, 23, "l");
            assert(false);
        }
        catch (FilmValidatorException & v) {
            assert(true);
        }
    }
    for(int an = 3000; an < 3005; an++) {
        try {
            aController->addFilm("film11", "c", an, 23, "l");
            assert(false);
        }
        catch (FilmValidatorException & v) {
            assert(true);
        }
    }
    for(int an = 2001; an < 2005; an++) {
        try {
            aController->addFilm("film11", "c", an, 23, "l");
            assert(false);
        }
        catch (FilmRepoException & r) {
            assert(true);
        }
    }
    for(int an = 2001; an < 2005; an++) {
        aController->deleteFilm("film11", an);
    }

    delete fRepo;
    delete aController;
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

    for(int an = -1; an < 3; an++) {
        try {
            aController->deleteFilm("film11", an);
            assert(false);
        }
        catch (FilmValidatorException & v) {
            assert(true);
        }
    }
    for(int an = 3000; an < 3005; an++) {
        try {
            aController->deleteFilm("film11", an);
            assert(false);
        }
        catch (FilmValidatorException & v) {
            assert(true);
        }
    }

    delete fRepo;
    delete aController;
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

    for(int an = 2001; an < 2005; an++) {
        try {
            aController->modifyTitel("f", an, "film12");
            assert(false);
        }
        catch (FilmRepoException & r) {
            assert(true);
        }
    }

    for(int an = 20; an < 25; an++) {
        try {
            aController->modifyTitel("f", an, "film12");
            assert(false);
        }
        catch (FilmValidatorException & r) {
            assert(true);
        }
    }

    for(int an = 2001; an < 2005; an++) {
        aController->modifyGenre("film12", an, "g");
        assert(aController->showFilms().find(Film("film12", "g", an, 23, "l").showFilm()) != std::string::npos);
    }

    for(int an = 2001; an < 2005; an++) {
        try {
            aController->modifyGenre("f", an, "g");
            assert(false);
        }
        catch (FilmRepoException & r) {
            assert(true);
        }
    }

    for(int an = 20; an < 25; an++) {
        try {
            aController->modifyGenre("f", an, "g");
            assert(false);
        }
        catch (FilmValidatorException & r) {
            assert(true);
        }
    }

    for(int an = 2001; an < 2005; an++) {
        aController->modifyYear("film12", an, 2015);
        assert(aController->showFilms().find(Film("film12", "g", 2015, 23, "l").showFilm()) != std::string::npos);
    }

    for(int an = 2001; an < 2005; an++) {
        try {
            aController->modifyYear("f", an, 2015);
            assert(false);
        }
        catch (FilmRepoException & r) {
            assert(true);
        }
    }

    for(int an = 20; an < 25; an++) {
        try {
            aController->modifyYear("f", an, 2);
            assert(false);
        }
        catch (FilmValidatorException & r) {
            assert(true);
        }
    }

    for(int an = 2001; an < 2005; an++) {
        aController->deleteFilm("film12", 2015);
    }

    delete fRepo;
    delete aController;
}

void testAddUser(){
    FilmRepository * fRepo = new FilmRepository();

    BenutzerController * bController = new BenutzerController(fRepo);

    bController->addUser("ana", "maria");
//    std::cout << bController->getBenutzerByIndex(10)->getName() << std::endl;
//    std::cout << bController->getBenutzerByIndex(10)->getVorname() << std::endl;
    assert(bController->getBenutzerByIndex(10)->getName() == "maria" and bController->getBenutzerByIndex(10)->getVorname() == "ana");

    try {
        bController->addUser("ana", "maria");
        assert(false);
    }
    catch (FilmRepoException & r) {
        assert(true);
    }

    bController->removeUser("ana", "maria");

    delete fRepo;
    delete bController;
}

void testDeleteUser(){
    FilmRepository * fRepo = new FilmRepository();

    BenutzerController * bController = new BenutzerController(fRepo);

    bController->addUser("ana", "maria");
    assert(bController->getBenutzerByIndex(10)->getName() == "maria" && bController->getBenutzerByIndex(10)->getVorname() == "ana");
    assert(bController->getAllBenutzer().size() == 11);

    bController->removeUser("ana", "maria");
    assert(bController->getAllBenutzer().size() == 10);

    try {
        bController->removeUser("ana", "maria");
        assert(false);
    }
    catch (FilmRepoException & r) {
        assert(true);
    }

    delete fRepo;
    delete bController;
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
