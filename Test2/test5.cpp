//
// Created by Victor on 24.11.2020.
//
#define CATCH_CONFIG_MAIN

#include "catch_amalgamated.hpp"
#include "Polynomial.h"
#include "PolynomialQueue.h"
#include <sstream>

//тестирование коректности создания
TEST_CASE("PolynomialQueue Test Create", "[Polynomial Queue Test]"){
    PolynomialQueue queue;
}

//тестирование коректности добавления удаления элемента
TEST_CASE("Polynomial Queue Push/Pop Test", "[Polynomial Queue Test]"){
    PolynomialQueue queue;

    {
        double arr[] = {1, 2, 3};
        unsigned int len = sizeof(arr) / sizeof(double);
        auto* p1 = new Polynomial(arr, len);
        auto* p2 = new Polynomial(arr, len);
        auto* p3 = new Polynomial(arr, len);
        p2->setCoefficient(5, 0);
        p3->setCoefficient(10, 0);
        
        queue.push(p1);
        queue.push(p2);
        queue.push(p3);
    }

    {
        Polynomial* p1 = queue.pop();
        Polynomial* p2 = queue.pop();
        Polynomial* p3 = queue.pop();
        
        REQUIRE(p1->getCoefficient(0) == 1);
        REQUIRE(p2->getCoefficient(0) == 5);
        REQUIRE(p3->getCoefficient(0) == 10);
    }
}

//тестирование вставки элемента
TEST_CASE("Polynomial Queue Insert Test", "[Polynomial Queue Test]"){
    PolynomialQueue queue;

    {
        double arr[] = {1, 2, 3};
        unsigned int len = sizeof(arr) / sizeof(double);
        auto* p1 = new Polynomial(arr, len);
        auto* p2 = new Polynomial(arr, len);
        auto* p3 = new Polynomial(arr, len);
        p2->setCoefficient(5, 0);
        p3->setCoefficient(10, 0);
        
        queue.push(p1);
        queue.push(p2);
        queue.insert(p3,1);
    }

    {
        Polynomial* p1 = queue.pop();
        Polynomial* p2 = queue.pop();
        Polynomial* p3 = queue.pop();
        
        REQUIRE(p1->getCoefficient(0) == 1);
        REQUIRE(p2->getCoefficient(0) == 10);
        REQUIRE(p3->getCoefficient(0) == 5);
        
        try {
            queue.pop();
            FAIL("should be Exception: \"Out of Range Array\"\n");
        }catch(PolynomialQueueException& e){
            REQUIRE(e.what() == std::string("Out of Range Array"));
        }
        
    }
}

//тестирование удаления элемента
TEST_CASE("Polynomial Queue Remove Test", "[Polynomial Queue Test]"){
    PolynomialQueue queue;
    
    {
        double arr[] = {1, 2, 3};
        unsigned int len = sizeof(arr) / sizeof(double);
        auto* p1 = new Polynomial(arr, len);
        auto* p2 = new Polynomial(arr, len);
        auto* p3 = new Polynomial(arr, len);
        p2->setCoefficient(5, 0);
        p3->setCoefficient(10, 0);
        
        queue.push(p1);
        queue.push(p2);
        queue.push(p3);
    }
    
    queue.remove(1);
    
    {
        Polynomial* p1 = queue.pop();
        Polynomial* p2 = queue.pop();

        REQUIRE(p1->getCoefficient(0) == 1);
        REQUIRE(p2->getCoefficient(0) == 10);
        
        try {
            queue.pop();
            FAIL("should be Exception: \"Out of Range Array\"\n");
        }catch(PolynomialQueueException& e){
            REQUIRE(e.what() == std::string("Out of Range Array"));
        }
        
    }
}

//тестирование получения элемента по номеру
TEST_CASE("Polynomial Queue Get Test", "[Polynomial Queue Test]"){
    PolynomialQueue queue;

    {
        double arr[] = {1, 2, 3};
        unsigned int len = sizeof(arr) / sizeof(double);
        auto* p1 = new Polynomial(arr, len);
        auto* p2 = new Polynomial(arr, len);
        auto* p3 = new Polynomial(arr, len);
        p2->setCoefficient(5, 0);
        p3->setCoefficient(10, 0);

        queue.push(p1);
        queue.push(p2);
        queue.push(p3);
    }

    {
        Polynomial* p1 = queue.get(1);
        Polynomial* p2 = queue.get(2);
        Polynomial* p3 = queue.get(0);

        REQUIRE(p1->getCoefficient(0) == 5);
        REQUIRE(p2->getCoefficient(0) == 1);
        REQUIRE(p3->getCoefficient(0) == 10);

        try {
            queue.get(10);
            FAIL("should be Exception: \"Out of Range Array\"\n");
        }catch(PolynomialQueueException& e){
            REQUIRE(e.what() == std::string("Out of Range Array"));
        }

    }
}

//тестирование вывода в строку
TEST_CASE("Polynomial Queue OutStream Test", "[Polynomial Queue Test]"){
    PolynomialQueue queue;

    {
        double arr[] = {1, 2, 3};
        unsigned int len = sizeof(arr) / sizeof(double);
        auto* p1 = new Polynomial(arr, len);
        auto* p2 = new Polynomial(arr, len);
        auto* p3 = new Polynomial(arr, len);
        p2->setCoefficient(5, 0);
        p3->setCoefficient(10, 0);

        queue.push(p1);
        queue.push(p2);
        queue.push(p3);
    }

    std::stringstream stream;
    stream << queue;

    REQUIRE(stream.str() == "10+2x^1+3x^2\n5+2x^1+3x^2\n1+2x^1+3x^2\n");
}