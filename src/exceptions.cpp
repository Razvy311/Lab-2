//
// Created by Nikos on 5/24/2020.
//

#include "exceptions.h"

FilmRepoException::FilmRepoException(const std::string& exception) : exception_name(exception) {}
FilmValidatorException::FilmValidatorException(const std::string& exception) : exception_name(exception) {}
BenutzerRepoException::BenutzerRepoException(const std::string& exception) : exception_name(exception) {}
DatabaseException::DatabaseException(const std::string& exception) : exception_name(exception) {}

const char* FilmRepoException::what() {
    return exception_name.c_str();
}
const char* FilmValidatorException::what() {
    return exception_name.c_str();
}
const char* BenutzerRepoException::what() {
    return exception_name.c_str();
}
const char* DatabaseException::what() {
    return exception_name.c_str();
}