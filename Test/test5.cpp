//
// Created by Victor on 24.11.2020.
//

#include <gtest/gtest.h>
#include "PolynomialQueue.h"

class PolynomialQueueTest : public testing::Test {};

TEST(PolynomialQueueTest, PolynomialQueueCreateTest){
    PolynomialQueue queue;
}

TEST(PolynomialQueueTest, PolynomialQueuePushPopTest){
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

        ASSERT_EQ(p1->getCoefficient(0),1);
        ASSERT_EQ(p2->getCoefficient(0),5);
        ASSERT_EQ(p3->getCoefficient(0),10);
    }
}

TEST(PolynomialQueueTest, PolynomialQueueInsertTest){
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

        ASSERT_EQ(p1->getCoefficient(0),1);
        ASSERT_EQ(p2->getCoefficient(0),10);
        ASSERT_EQ(p3->getCoefficient(0),5);

        try {
            Polynomial* p4 = queue.pop();
            FAIL() << "should be Exception: \"Out of Range Array\"\n";
        }catch(PolynomialQueueException& e){
            ASSERT_EQ(e.what(),std::string("Out of Range Array"));
        }

    }
}

TEST(PolynomialQueueTest, PolynomialQueueRemoveTest){
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

        ASSERT_EQ(p1->getCoefficient(0),1);
        ASSERT_EQ(p2->getCoefficient(0),10);

        try {
            Polynomial* p3 = queue.pop();
            FAIL() << "should be Exception: \"Out of Range Array\"\n";
        }catch(PolynomialQueueException& e){
            ASSERT_EQ(e.what(),std::string("Out of Range Array"));
        }

    }
}

TEST(PolynomialQueueTest, PolynomialQueueGetTest){
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

        ASSERT_EQ(p1->getCoefficient(0),5);
        ASSERT_EQ(p2->getCoefficient(0),1);
        ASSERT_EQ(p3->getCoefficient(0),10);

        try {
            Polynomial* p4 = queue.get(10);
            FAIL() << "should be Exception: \"Out of Range Array\"\n";
        }catch(PolynomialQueueException& e){
            ASSERT_EQ(e.what(),std::string("Out of Range Array"));
        }

    }
}

TEST(PolynomialQueueTest, PolynomialQueueOotStreamTest){
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
    
    ASSERT_EQ(stream.str(),"10+2x^1+3x^2\n5+2x^1+3x^2\n1+2x^1+3x^2\n");
}