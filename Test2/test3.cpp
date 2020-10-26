//
// Created by Victor on 24.10.2020.
//

#define CATCH_CONFIG_MAIN

#include "catch_amalgamated.hpp"
#include "Polynomial.h"
#include <sstream>
#include <fstream>

//тестирование вывода в строку
TEST_CASE("OutputStreamTest", "[out to string]") {
    double array[] = {1, 2, 3};
    unsigned int len = sizeof(array) / sizeof(double);
    Polynomial p(array, len);

    std::stringstream stream("");

    stream << p;

    REQUIRE(stream.str() == "1+2x^1+3x^2");
}

//тестирование ввода из строки
TEST_CASE("InputStreamTest", "[input from string]") {
    double array[] = {1, 2, 3};
    unsigned int len = sizeof(array) / sizeof(double);
    Polynomial p(array, len);

    std::stringstream stream("10+7x^1+22x^2");
    stream >> p;

    REQUIRE(std::string("10+7x^1+22x^2") == p.toString());
}

//тестирование вывода и ввода из файла
TEST_CASE("Output/InputStreamTest", "[out/in to text file]") {
    {
        double array[] = {1, 2, 3};
        unsigned int len = sizeof(array) / sizeof(double);
        Polynomial p(array, len);

        std::ofstream stream("test3_1.txt");

        stream << p;
        stream.flush();
        stream.close();
    }

    {
        double array[] = {0};
        unsigned int len = sizeof(array) / sizeof(double);
        Polynomial p(array, len);

        std::ifstream stream("test3_1.txt");

        stream >> p;

        REQUIRE(std::string("1+2x^1+3x^2") == p.toString());
    }
}