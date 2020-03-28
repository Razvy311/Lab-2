#include "repo.h"

std::vector<Schokolade> SchokoladeRepo::getAll(){
    return schoko;
}

bool SchokoladeRepo::addSchokolade(std::string name, std::string typ, double preis){
    for(auto currentSchoko = schoko.begin(); currentSchoko != schoko.end(); ++currentSchoko){
        if(currentSchoko->getName() == name){
            return false;
        }
    }
    schoko.push_back(Schokolade(name, typ, preis));
    return true;
}