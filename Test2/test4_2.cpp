//
// Created by Victor on 10.11.2020.
//

#include "catch_amalgamated.hpp"
#include "Polynomial.h"
#include "PolynomialExp.h"
#include <sstream>

TEST_CASE("Create Polynomial Exp","[CreatePolynomialExp]"){
    double arr[] = {1,2,3};
    int exps[] = {1,2,3};
    unsigned int len = 3;
    PolynomialExp p(arr,exps,len);
    
    REQUIRE(p[0] == 1);
    REQUIRE(p[1] == 2);
    REQUIRE(p[2] == 3);
    
    REQUIRE(p.getExp(0) == 1);
    REQUIRE(p.getExp(1) == 2);
    REQUIRE(p.getExp(2) == 3);
    
    REQUIRE(p.toString() == std::string("1+2^2x^1+3^3x^2"));
}

TEST_CASE("Get Value Test","[GetValueTest]"){
    double arr[] = {1,2,3};
    int exps[] = {1,2,3};
    unsigned int len = 3;
    PolynomialExp p(arr,exps,len);

    REQUIRE(p(1) == 32);
}

TEST_CASE("Inc/Dec Test", "[IncDecTest]"){
    {
        double arr[] = {1,2,3};
        int exps[] = {1,2,3};
        unsigned int len = 3;
        PolynomialExp p(arr,exps,len);

        PolynomialExp p2 = p++;

        REQUIRE(p2[0] == 1);
        REQUIRE(p2[1] == 2);
        REQUIRE(p2[2] == 3);

        REQUIRE(p2.getExp(0) == 1);
        REQUIRE(p2.getExp(1) == 2);
        REQUIRE(p2.getExp(2) == 3);

        REQUIRE(p[0] == 1);
        REQUIRE(p[1] == 2);
        REQUIRE(p[2] == 3);
        REQUIRE(p[3] == 0);

        REQUIRE(p.getExp(0) == 1);
        REQUIRE(p.getExp(1) == 2);
        REQUIRE(p.getExp(2) == 3);
        REQUIRE(p.getExp(3) == 1);
    }

    {
        double arr[] = {1,2,3};
        int exps[] = {1,2,3};
        unsigned int len = 3;
        PolynomialExp p(arr,exps,len);
    
        PolynomialExp p2 = p--;
    
        REQUIRE(p2[0] == 1);
        REQUIRE(p2[1] == 2);
        REQUIRE(p2[2] == 3);
    
        REQUIRE(p2.getExp(0) == 1);
        REQUIRE(p2.getExp(1) == 2);
        REQUIRE(p2.getExp(2) == 3);
    
        REQUIRE(p[0] == 1);
        REQUIRE(p[1] == 2);
    
        REQUIRE(p.getExp(0) == 1);
        REQUIRE(p.getExp(1) == 2);

        try {
            p[2];
            p.getExp(2);
            FAIL("should be Exception: \"Out of Range Array\"\n");
        }catch(PolynomialException& e){
            REQUIRE(e.what() == std::string("Out of Range Array"));
        }

    }

    {
        double arr[] = {1,2,3};
        int exps[] = {1,2,3};
        unsigned int len = 3;
        PolynomialExp p(arr,exps,len);
    
        PolynomialExp p2 = ++p;
    
        REQUIRE(p2[0] == 1);
        REQUIRE(p2[1] == 2);
        REQUIRE(p2[2] == 3);
        REQUIRE(p2[3] == 0);
    
        REQUIRE(p2.getExp(0) == 1);
        REQUIRE(p2.getExp(1) == 2);
        REQUIRE(p2.getExp(2) == 3);
        REQUIRE(p2.getExp(3) == 1);
    
        REQUIRE(p[0] == 1);
        REQUIRE(p[1] == 2);
        REQUIRE(p[2] == 3);
        REQUIRE(p[3] == 0);
    
        REQUIRE(p.getExp(0) == 1);
        REQUIRE(p.getExp(1) == 2);
        REQUIRE(p.getExp(2) == 3);
        REQUIRE(p.getExp(3) == 1);
    }

    {
        double arr[] = {1,2,3};
        int exps[] = {1,2,3};
        unsigned int len = 3;
        PolynomialExp p(arr,exps,len);
    
        PolynomialExp p2 = --p;
    
        REQUIRE(p[0] == 1);
        REQUIRE(p[1] == 2);
        REQUIRE(p.getExp(0) == 1);
        REQUIRE(p.getExp(1) == 2);
    
        try {
            p[2];
            p.getExp(2);
            FAIL("should be Exception: \"Out of Range Array\"\n");
        }catch(PolynomialException& e){
            REQUIRE(e.what() == std::string("Out of Range Array"));
        }

    }
}

TEST_CASE("Plus Minux Test","[PlusMinuxTest]"){
    {
        double arr[] = {1,2,3};
        int len = 3;
        Polynomial p(arr,len);
        
        int exps[] = {1,2,3};
        PolynomialExp p2(arr,exps,len);
        
        Polynomial p3 = p + p2;
        
        REQUIRE(p3[0] == 2);
        REQUIRE(p3[1] == 6);
        REQUIRE(p3[2] == 30);
    }
    
    {
        double arr[] = {1,2,3};
        int len = 3;
        Polynomial p(arr,len);
        
        int exps[] = {1,2,3};
        PolynomialExp p2(arr,exps,len);
        
        Polynomial p3 = p2 + p;
        
        REQUIRE(p3[0] == 2);
        REQUIRE(p3[1] == 6);
        REQUIRE(p3[2] == 30);
    }
    
    {
    double arr[] = {1,2,3};
    int len = 3;
    Polynomial p(arr,len);
    
    int exps[] = {1,2,3};
    PolynomialExp p2(arr,exps,len);
    
    Polynomial p3 = p2 + p2;
    
    REQUIRE(p3[0] == 2);
    REQUIRE(p3[1] == 8);
    REQUIRE(p3[2] == 54);
    }
    {
    double arr[] = {1,2,3};
    int len = 3;
    Polynomial p(arr,len);
    
    int exps[] = {1,2,3};
    PolynomialExp p2(arr,exps,len);
    
    Polynomial p3 = p - p2;
    
    REQUIRE(p3[0] == 0);
    REQUIRE(p3[1] == -2);
    REQUIRE(p3[2] == -24);
    }
    
    {
    double arr[] = {1,2,3};
    int len = 3;
    Polynomial p(arr,len);
    
    int exps[] = {1,2,3};
    PolynomialExp p2(arr,exps,len);
    
    Polynomial p3 = p2 - p;
    
    REQUIRE(p3[0] == 0);
    REQUIRE(p3[1] == 2);
    REQUIRE(p3[2] == 24);
    }
    
    {
    double arr[] = {1,2,3};
    int len = 3;
    Polynomial p(arr,len);
    
    int exps[] = {1,2,3};
    PolynomialExp p2(arr,exps,len);
    
    Polynomial p3 = p2 - p2;
    
    REQUIRE(p3[0] == 0);
    REQUIRE(p3[1] == 0);
    REQUIRE(p3[2] == 0);
    }
}