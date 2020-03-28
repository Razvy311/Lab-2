#include "repo.h"

#include <iostream>

int main(){

    SchokoladeRepo r = SchokoladeRepo();
    r.addSchokolade("milka", "dark", 5.20);
    r.addSchokolade("poiana", "milk", 3.30);
    r.addSchokolade("bucuria", "scufita rosie", 2.00);

    std::vector<Schokolade> schoko = r.getAll();
    for(auto s = schoko.begin(); s != schoko.end(); ++s){
        std::cout<<s->printSchoko()<<'\n';
    }

    return 0;
}