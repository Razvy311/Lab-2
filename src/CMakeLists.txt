cmake_minimum_required(VERSION 3.17)
project(src)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS --coverage)

include_directories(.)

add_executable(src
        AdminController.cpp
        AdminController.h
        Benutzer.cpp
        Benutzer.h
        BenutzerController.cpp
        BenutzerController.h
        BenutzerRepository.cpp
        BenutzerRepository.h
        exceptions.cpp
        exceptions.h
        Film.cpp
        Film.h
        FilmRepository.cpp
        FilmRepository.h
        IORepoAbstract.h
        tests.cpp
        tests.h
        UI.cpp)
