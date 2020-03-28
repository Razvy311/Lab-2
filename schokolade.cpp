#include "schokolade.h"

Schokolade::Schokolade(std::string name, std::string typ, double preis){
    // Constructor for the instance "Schokolade".
    this->name = name;
    this->typ = typ;
    this->preis = preis;
}

// GETTERS.
std::string Schokolade::getName(){
    // This method returns the name of the choclate.
    // @return: a string symbolising the name.
    return name;
}

std::string Schokolade::getTyp(){
    // This method returns the type of the chocolate.
    // @return: a string symbolising the type.
    return typ;
}

double Schokolade::getPreis(){
    // This method returns the price of the chocolate.
    // @return: a real number symbolising the price.
    return preis;
}

// SETTERS.
void Schokolade::setName(std::string newName){
    // This method changes the former name with a new one.
    // @param newName: a string representing the name to be changed with.
    name = newName;
} 
void Schokolade::setTyp(std::string newTyp){
    // This method changes the former type with a new one.
    // @param newTyp: a string representing the type to be changed with.
    typ = newTyp;
}
void Schokolade::setPreis(double neuPreis){
    // This methods changes the former price with a new one.
    // @param neuPreis: a real number representing the price to be changed with.
    preis = neuPreis;
}