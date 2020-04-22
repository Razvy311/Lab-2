//
// Created by Nikos on 4/22/2020.
//

#ifndef LAB5_VALIDATOREXCEPTION_H
#define LAB5_VALIDATOREXCEPTION_H

#include <string>
#include <algorithm>
#include <exception>

class ValidatorException : public std::exception{
    // Exception in case the values are not proper.
    public:
        ValidatorException(){};
        std::string errorMessage(){ return "Invalid data."; }
};

#endif //LAB5_VALIDATOREXCEPTION_H
