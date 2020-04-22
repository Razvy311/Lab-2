//
// Created by Nikos on 4/22/2020.
//

#ifndef LAB5_REPOEXCEPTION_H
#define LAB5_REPOEXCEPTION_H

#include <exception>
#include <algorithm>
#include <string>

class RepoException : public std::exception{
    // Creates repository exceptions.
    public:
        RepoException(){}
        std::string doesntExist(){ return "The searched film doesn't exist."; }
        std::string alreadyExist(){ return "The film already exists."; }
};

#endif //LAB5_REPOEXCEPTION_H
