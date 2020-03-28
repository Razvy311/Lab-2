#pragma once

#include "schokolade.h"
#include <vector>

class SchokoladeRepo{
    private:
        std::vector<Schokolade> schoko;
    public:
    
        // Getter.
        std::vector<Schokolade> getAll();

        bool addSchokolade(std::string name, std::string typ, double preis);
};