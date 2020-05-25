//
// Created by Nikos on 4/22/2020.
//

#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H

#include "FilmRepository.h"

class AdminController{
    private:
        FilmRepository* films;

    public:
        // Class constructor.
        AdminController(FilmRepository* repo);
        ~AdminController();

        // Methods:
        void addFilm(std::string titel, std::string genre, int year, int likes, std::string link);
        void deleteFilm(std::string titel, int year);
        void modifyTitel(std::string titel, int year, std::string newTitel);
        void modifyGenre(std::string, int year, std::string newGenre);
        void modifyYear(std::string titel, int year, int newYear);
        void modifyLikes(std::string titel, int year, int newLikes);
        void modufyLink(std::string titel, int year, std::string newLink);
        std::string showFilms();
};

#endif // ADMINCONTROLLER_H
