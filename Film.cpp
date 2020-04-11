#include "Film.h"

// Constructor for the class.
Film::Film(std::string titel, std::string genre, int erscheinungsjahr, int anzahlLikes, std::string trailer){
    // Creates an instance.
    this->titel = titel;
    this->genre = genre;
    this->erscheinungsjahr = erscheinungsjahr;
    this->anzahlLikes = anzahlLikes;
    this->linkTrailer = trailer;
}

// Getters.
/*
    This method gets the titel of the film.
    @return: a string, the titel of the film
*/
std::string Film::getTitel(){
    return this->titel;
}

/*
    This method gets the genre of the film.
    @return: a string, the genre of the film
*/
std::string Film::getGenre(){
    return this->genre;
}

/*
    This method gets the publishing year of the film.
    @return: an integer, the publishing of the film
*/
int Film::getErscheinungsjahr(){
    return this->erscheinungsjahr;
}

/*
    This method gets the number of likes of the film.
    @return: an integer, the number of likes of the film
*/
int Film::getAnzahlLikes(){
    return this->anzahlLikes;
}

/*
    This method gets the link to the trailer of the film.
    @return: a string, the link to the trailer of the film
*/
std::string Film::getLinkTrailer(){
    return this->linkTrailer;
}

// Setters.
/*
    This method changes the titel of the film.
    @param newTitel: a string, the new titel
*/
void Film::setTitel(std::string newTitel){
    this->titel = newTitel;
}

/*
    This method changes the genre of the film.
    @param newGenre: a string, the new genre
*/
void Film::setGenre(std::string newGenre){
    this->genre = newGenre;
}

/*
    This method changes the publishing year of the film.
    @param newErscheinungsjahr: an integer, the new publishing year
*/
void Film::setErscheinungsjahr(int newErscheinungsjahr){
    this->erscheinungsjahr = newErscheinungsjahr;
}

/*
    This method changes the number of likes of the film.
    @param newLikes: an integer, the new number of likes
*/
void Film::setAnzahlLikes(int newLikes){
    this->anzahlLikes = newLikes;
}

/*
    This method changes the link to the trailer of the film.
    @param newLink: a string, the new link
*/
void Film::setLinkTrailer(std::string newLink){
    this->linkTrailer = newLink;
}

// String.
/*
    This method returns the string containing the data of the film to be printed.
    @return: a string containing the film
*/
std::string Film::showFilm(){
    return titel + " " + genre + " " + std::to_string(erscheinungsjahr) + " " + std::to_string(anzahlLikes) + " " + linkTrailer;
}
