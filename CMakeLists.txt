cmake_minimum_required(VERSION 3.17.5)
project(BeerCalculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(BeerCalculator
        main.cpp
        Console.cpp
        Console.h
        Recipe.cpp
        Recipe.h
        Hop.cpp
        Hop.h)