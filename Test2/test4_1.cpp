//
// Created by Victor on 10.11.2020.
//

#define CATCH_CONFIG_MAIN

#include "catch_amalgamated.hpp"
#include "Polynomial.h"
#include "PolynomialString.h"
#include <sstream>

//тестирование коректности создания экземпляра класса
TEST_CASE("Create Test","[CreateTest]"){
    PolynomialString p = "1+2x^1+4x^5";
    REQUIRE(p.toString() == std::string("1+2x^1+4x^5"));

    REQUIRE(p[0] == 1);
    REQUIRE(p[1] == 2);
    REQUIRE(p[2] == 0);
    REQUIRE(p[3] == 0);
    REQUIRE(p[4] == 0);
    REQUIRE(p[5] == 4);
}

//тестирование коректности создания экземпляра класса
TEST_CASE("CreateTest2","[CreateTest2]"){
    double arr[] = {1,2,3};
    unsigned int len = 3;
    PolynomialString p(arr,len);
    
    REQUIRE(p.toString() == std::string("1+2x^1+3x^2"));

    REQUIRE(p[0] == 1);
    REQUIRE(p[1] == 2);
    REQUIRE(p[2] == 3);
}

//тестирование перегрузки инкремента/декремента
TEST_CASE("IncDecTest","[IncDecTest]"){
    {
        PolynomialString p = "1+2x^1+3x^2";
        PolynomialString p2 = p++;
        
        
        REQUIRE(p2[0] == 1);
        REQUIRE(p2[1] == 2);
        REQUIRE(p2[2] == 3);
        
        REQUIRE(p[0] == 1);
        REQUIRE(p[1] == 2);
        REQUIRE(p[2] == 3);
        REQUIRE(p[3] == 0);
    }
    
    {
        PolynomialString p = "1+2x^1+3x^2";
        PolynomialString p2 = ++p;
        
        
        REQUIRE(p2[0] == 1);
        REQUIRE(p2[1] == 2);
        REQUIRE(p2[2] == 3);
        REQUIRE(p2[3] == 0);
        
        REQUIRE(p[0] == 1);
        REQUIRE(p[1] == 2);
        REQUIRE(p[2] == 3);
        REQUIRE(p[3] == 0);
    }
    
    {
        PolynomialString p = "1+2x^1+3x^2";
        PolynomialString p2 = p--;
        
        REQUIRE(p2[0] == 1);
        REQUIRE(p2[1] == 2);
        REQUIRE(p2[2] == 3);
        
        REQUIRE(p[0] == 1);
        REQUIRE(p[1] == 2);
        try {
            p[2];
            FAIL("should be Exception: \"Out of Range Array\"\n");
        }catch(PolynomialException& e){
            REQUIRE(e.what() == std::string("Out of Range Array"));
        }
    }
    
    {
        PolynomialString p = "1+2x^1+3x^2";
        PolynomialString p2 = --p;
        
        REQUIRE(p2[0] == 1);
        REQUIRE(p2[1] == 2);
        
        REQUIRE(p[0] == 1);
        REQUIRE(p[1] == 2);
        
        try {
            p[2];
            p2[2];
            FAIL("should be Exception: \"Out of Range Array\"\n");
        }catch(PolynomialException& e){
            REQUIRE(e.what() == std::string("Out of Range Array"));
        }
    }
}

//тестирование присвоения
TEST_CASE("SetTest","[SetTest]"){
    PolynomialString p = "1+2x^1+4x^2";
    p.setCoefficient(5,1);
    REQUIRE(p.toString() == std::string("1+5x^1+4x^2"));

    REQUIRE(p[0] == 1);
    REQUIRE(p[1] == 5);
    REQUIRE(p[2] == 4);
}