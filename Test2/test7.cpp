//
// Created by Victor on 09.12.2020.
//

#include "catch_amalgamated.hpp"
#include "Queue.h"
#include "Polynomial.h"

//тестирование создания объектов
TEST_CASE("Queue Test Create", "[Queue Test Create]"){
    Queue<int> queue_int;
    Queue<float> queue_float;
    Queue<Polynomial> queue_polynomial;
}

//тестирование вставки у изъяьтя элемента
TEST_CASE("Queue Push Pop Test", "[Queue Push Pop Test]"){
    {
        Queue<int> queue;
        {
            queue.push(1);
            queue.push(5);
            queue.push(10);
        }

        {
            int a = queue.pop();
            int b = queue.pop();
            int c = queue.pop();

            REQUIRE(a ==  1);
            REQUIRE(b ==  5);
            REQUIRE(c ==  10);
        }
    }

    {
        Queue<float> queue;
        {
            queue.push(1.5f);
            queue.push(5.5f);
            queue.push(10.5f);
        }

        {
            float a = queue.pop();
            float b = queue.pop();
            float c = queue.pop();

            REQUIRE(a ==  1.5f);
            REQUIRE(b ==  5.5f);
            REQUIRE(c ==  10.5f);
        }
    }

    {
        Queue<Polynomial> queue;

        double arr[] = {1, 2, 3};
        unsigned int len = sizeof(arr) / sizeof(double);
        Polynomial p1(arr,len);
        Polynomial p2(arr,len);
        Polynomial p3(arr,len);

        p2.setCoefficient(5, 0);
        p3.setCoefficient(10, 0);
        queue.push(p1);
        queue.push(p2);
        queue.push(p3);

        {
            Polynomial a = queue.pop();
            Polynomial b = queue.pop();
            Polynomial c = queue.pop();

            REQUIRE(a ==  p1);
            REQUIRE(b ==  p2);
            REQUIRE(c ==  p3);
        }
    }
}

//тестирование вставки элемента
TEST_CASE("Queue Insert Test", "[QueueInsertTest]"){
    {
        Queue<int> queue;
        {

            queue.push(1);
            queue.push(4);
            queue.insert(10, 1);
        }

        {
            int p1 = queue.pop();
            int p2 = queue.pop();
            int p3 = queue.pop();

            REQUIRE(p1 ==  1);
            REQUIRE(p2 ==  10);
            REQUIRE(p3 ==  4);

            try {
                queue.pop();
                FAIL("should be Exception: \"Queue is empty\"\n");
            } catch (QueueException &e) {
                REQUIRE(e.what() == std::string("Queue is empty"));
            }

        }
    }

    {
        Queue<float> queue;
        {

            queue.push(1.5f);
            queue.push(4.5f);
            queue.insert(10.5f, 1);
        }

        {
            float p1 = queue.pop();
            float p2 = queue.pop();
            float p3 = queue.pop();

            REQUIRE(p1 ==  1.5f);
            REQUIRE(p2 ==  10.5f);
            REQUIRE(p3 ==  4.5f);

            try {
                queue.pop();
                FAIL("should be Exception: \"Queue is empty\"\n");
            } catch (QueueException &e) {
                REQUIRE(e.what() == std::string("Queue is empty"));
            }

        }
    }

    {
        Queue<Polynomial> queue;
        double arr[] = {1, 2, 3};
        unsigned int len = sizeof(arr) / sizeof(double);
        Polynomial p1(arr,len);
        Polynomial p2(arr,len);
        Polynomial p3(arr,len);

        queue.push(p1);
        queue.push(p2);
        queue.insert(p3, 1);

        {
            Polynomial a = queue.pop();
            Polynomial b = queue.pop();
            Polynomial c = queue.pop();

            REQUIRE(a ==  p1);
            REQUIRE(b ==  p3);
            REQUIRE(c ==  p2);

            try {
                queue.pop();
                FAIL("should be Exception: \"Queue is empty\"\n");
            } catch (QueueException &e) {
                REQUIRE(e.what() == std::string("Queue is empty"));
            }

        }
    }
}

//тестирование удаления
TEST_CASE("Queue Remove Test", "[Queue Remove Test]"){
    {
        Queue<int> queue;
        {

            queue.push(1);
            queue.push(5);
            queue.push(10);
            queue.remove(1);
        }
        {
            int p1 = queue.pop();
            int p2 = queue.pop();

            REQUIRE(p1 ==  1);
            REQUIRE(p2 ==  10);

            try {
                queue.pop();
                FAIL("should be Exception: \"Queue is empty\"\n");
            } catch (QueueException &e) {
                REQUIRE(e.what() == std::string("Queue is empty"));
            }

        }
    }

    {
        Queue<float> queue;
        {

            queue.push(1.5f);
            queue.push(5.5f);
            queue.push(10.5f);
            queue.remove(1);
        }
        {
            float p1 = queue.pop();
            float p2 = queue.pop();

            REQUIRE(p1 ==  1.5f);
            REQUIRE(p2 ==  10.5f);

            try {
                queue.pop();
                FAIL("should be Exception: \"Queue is empty\"\n");
            } catch (QueueException &e) {
                REQUIRE(e.what() == std::string("Queue is empty"));
            }

        }
    }

    {
        Queue<Polynomial> queue;
        double arr[] = {1, 2, 3};
        unsigned int len = sizeof(arr) / sizeof(double);
        Polynomial p1(arr,len);
        Polynomial p2(arr,len);
        Polynomial p3(arr,len);
        queue.push(p1);
        queue.push(p2);
        queue.push(p3);
        queue.remove(1);

        {
            Polynomial a = queue.pop();
            Polynomial b = queue.pop();

            REQUIRE(a ==  p1);
            REQUIRE(b ==  p2);

            try {
                queue.pop();
                FAIL("should be Exception: \"Queue is empty\"\n");
            } catch (QueueException &e) {
                REQUIRE(e.what() == std::string("Queue is empty"));
            }

        }
    }
}

//тестирование получения по номеру
TEST_CASE("Queue Get Test", "[Queue Get Test]"){
    {
        Queue<int> queue;

        {
            queue.push(1);
            queue.push(5);
            queue.push(10);
        }

        {
            int p1 = queue.get(1);
            int p2 = queue.get(2);
            int p3 = queue.get(0);

            REQUIRE(p1 ==  5);
            REQUIRE(p2 ==  1);
            REQUIRE(p3 ==  10);

            try {
                queue.get(10);
                FAIL("should be Exception: \"Out of Range Array\"\n");
            } catch (QueueException &e) {
                REQUIRE(e.what() == std::string("Out of Range Array"));
            }

        }
    }

    {
        Queue<float> queue;

        {
            queue.push(1.5f);
            queue.push(5.5f);
            queue.push(10.5f);
        }

        {
            float p1 = queue.get(1);
            float p2 = queue.get(2);
            float p3 = queue.get(0);

            REQUIRE(p1 ==  5.5f);
            REQUIRE(p2 ==  1.5f);
            REQUIRE(p3 ==  10.5f);

            try {
                queue.get(10);
                FAIL("should be Exception: \"Out of Range Array\"\n");
            } catch (QueueException &e) {
                REQUIRE(e.what() == std::string("Out of Range Array"));
            }

        }
    }

    {
        Queue<Polynomial> queue;
        double arr[] = {1, 2, 3};
        unsigned int len = sizeof(arr) / sizeof(double);
        Polynomial p1(arr,len);
        Polynomial p2(arr,len);
        Polynomial p3(arr,len);
        queue.push(p1);
        queue.push(p2);
        queue.push(p3);

        {
            Polynomial a = queue.get(1);
            Polynomial b = queue.get(2);
            Polynomial c = queue.get(0);

            REQUIRE(a ==  p2);
            REQUIRE(b ==  p3);
            REQUIRE(c ==  p1);

            try {
                queue.get(10);
                FAIL("should be Exception: \"Out of Range Array\"\n");
            } catch (QueueException &e) {
                REQUIRE(e.what() == std::string("Out of Range Array"));
            }

        }
    }
}