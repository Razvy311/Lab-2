//
// Created by Nikos on 5/24/2020.
//

#pragma once

#ifndef LAB_6_EXCEPTIONS_H
#define LAB_6_EXCEPTIONS_H

#include <exception>
#include <string>

class Exception : public std::exception {
public:
    virtual const char* what() = 0;
};

class FilmRepoException : public Exception {
private:
    const std::string& exception_name;
public:
    explicit FilmRepoException(const std::string& exception);
    const char* what() override;
};

class FilmValidatorException : public Exception {
private:
    const std::string& exception_name;
public:
    explicit FilmValidatorException(const std::string& exception);
    const char* what() override;
};

class BenutzerRepoException : public Exception {
private:
    const std::string& exception_name;
public:
    explicit BenutzerRepoException(const std::string& exception);
    const char* what() override;
};

class DatabaseException : public Exception {
private:
    const std::string& exception_name;
public:
    explicit DatabaseException(const std::string& exception);
    const char* what() override;
};

#endif //LAB_6_EXCEPTIONS_H
