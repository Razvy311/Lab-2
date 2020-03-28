#pragma once

#include <string>

class Schokolade{
    private:
        std::string name, typ;
        double preis;

    public:

        // Constructor.
        Schokolade(std::string name, std::string typ, double preis);

        // Getters.
        std::string getName();
        std::string getTyp();
        double getPreis();

        // Setters.
        void setName(std::string newName);
        void setTyp(std::string newTyp);
        void setPreis(double neuPreis);

        std::string printSchoko();
};