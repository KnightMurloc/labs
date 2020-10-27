//
// Created by Victor on 12.10.2020.
//

#include "Test2.h"
#include "../Polynomial.h"
#include <iostream>

using namespace std;

void operatorPlusTest() {
    {
        double array[5] = {4, 6, 3, 7, 6};
        unsigned int len = 5;
        Polynomial polynomial(array, len);

        double array2[5] = {-1, 2, 5, -7, 9};
        unsigned int len2 = 5;
        Polynomial polynomial2(array2, len2);

        Polynomial p3 = polynomial + polynomial2;
        if (
                p3.getCoefficient(0) != 3 ||
                p3.getCoefficient(1) != 8 ||
                p3.getCoefficient(2) != 8 ||
                p3.getCoefficient(3) != 0 ||
                p3.getCoefficient(4) != 15
                ) {
            cout << "Operator Plus Test Failed" << endl;
            return;
        }
    }
    {
        double array[5] = {4, 6, 3, 7, 6};
        unsigned int len = 5;
        Polynomial p(array, len);

        Polynomial p3 = p + p;

        if (
                p3.getCoefficient(0) != 8 ||
                p3.getCoefficient(1) != 12 ||
                p3.getCoefficient(2) != 6 ||
                p3.getCoefficient(3) != 14 ||
                p3.getCoefficient(4) != 12
                ) {
            cout << "Operator Plus Test Failed" << endl;
            return;
        }
    }

    {
        double array[5] = {4, 6, 3, 7, 6};
        unsigned int len = 5;
        Polynomial polynomial(array, len);

        double array2[] = {-1, 2, 5, -7, 9, 10, 15};
        unsigned int len2 = sizeof(array2) / sizeof(double);
        Polynomial polynomial2(array2, len2);

        Polynomial p3 = polynomial + polynomial2;
        if (
                p3.getCoefficient(0) != 3 ||
                p3.getCoefficient(1) != 8 ||
                p3.getCoefficient(2) != 8 ||
                p3.getCoefficient(3) != 0 ||
                p3.getCoefficient(4) != 15 ||
                p3.getCoefficient(5) != 10 ||
                p3.getCoefficient(6) != 15
                ) {
            cout << "Operator Plus Test Failed" << endl;
            return;
        }
    }

    cout << "Operator Plus Test Passed" << endl;
}

void operatorMinusTest() {
    {
        double array[5] = {4, 6, 3, 7, 6};
        unsigned int len = 5;
        Polynomial polynomial(array, len);

        double array2[5] = {-1, 2, 5, -7, 9};
        unsigned int len2 = 5;
        Polynomial polynomial2(array2, len2);

        Polynomial p3 = polynomial - polynomial2;
        if (
                p3.getCoefficient(0) != 5 ||
                p3.getCoefficient(1) != 4 ||
                p3.getCoefficient(2) != -2 ||
                p3.getCoefficient(3) != 14 ||
                p3.getCoefficient(4) != -3
                ) {
            cout << "Operator Minus Test Failed" << endl;
            return;
        }
    }
    {
        double array[5] = {4, 6, 3, 7, 6};
        unsigned int len = 5;
        Polynomial p(array, len);

        Polynomial p3 = p - p;

        if (
                p3.getCoefficient(0) != 0 ||
                p3.getCoefficient(1) != 0 ||
                p3.getCoefficient(2) != 0 ||
                p3.getCoefficient(3) != 0 ||
                p3.getCoefficient(4) != 0
                ) {
            cout << "Operator Minus Test Failed" << endl;
            return;
        }
    }
    {
        double array[5] = {4, 6, 3, 7, 6};
        unsigned int len = 5;
        Polynomial polynomial(array, len);

        double array2[] = {-1, 2, 5, -7, 9, 10, 15};
        unsigned int len2 = sizeof(array2) / sizeof(double);
        Polynomial polynomial2(array2, len2);

        Polynomial p3 = polynomial - polynomial2;
        if (
                p3.getCoefficient(0) != 5 ||
                p3.getCoefficient(1) != 4 ||
                p3.getCoefficient(2) != -2 ||
                p3.getCoefficient(3) != 14 ||
                p3.getCoefficient(4) != -3 ||
                p3.getCoefficient(5) != -10 ||
                p3.getCoefficient(6) != -15
                ) {
            cout << p3.toString() << endl;
            cout << "Operator Minus Test Failed" << endl;
            return;
        }
    }

    cout << "Operator Minus Test Passed" << endl;
}

void incrementDecrementTest() {
    {
        double array[5] = {4, 6, 3};
        unsigned int len = 5;
        Polynomial p(array, len);
        Polynomial p2 = p++;

        if (
                p.getCoefficient(0) != 4 ||
                p.getCoefficient(1) != 6 ||
                p.getCoefficient(2) != 3
                ) {
            try {
                p2.getCoefficient(3);
                cout << "increment/Decrement Test Failed" << endl;
                return;
            } catch (PolynomialException &e) {}

        }
    }

    {
        double array[5] = {4, 6, 3};
        unsigned int len = 5;
        Polynomial p(array, len);
        Polynomial p2 = ++p;
        try {
            if (
                    p.getCoefficient(0) != 4 ||
                    p.getCoefficient(1) != 6 ||
                    p.getCoefficient(2) != 3 ||
                    p.getCoefficient(3) != 0
                    ) {
                cout << "increment/Decrement Test Failed" << endl;
                return;
            }
        } catch (PolynomialException &e) {
            cout << "increment/Decrement Test Failed" << endl;
            return;
        }

    }

    {
        double array[5] = {4, 6, 3};
        unsigned int len = 5;
        Polynomial p(array, len);
        Polynomial p2 = p--;

        try {


            if (
                    p.getCoefficient(0) != 4 ||
                    p.getCoefficient(1) != 6 ||
                    p.getCoefficient(2) != 3
                    ) {
                try {
                    p2.getCoefficient(2);
                    cout << "increment/Decrement Test Failed" << endl;
                    return;
                } catch (PolynomialException &e) {}

            }
        } catch (PolynomialException &e) {
            cout << "increment/Decrement Test Failed" << endl;
            return;
        }
    }

    {
        double array[5] = {4, 6, 3};
        unsigned int len = 5;
        Polynomial p(array, len);
        Polynomial p2 = ++p;
        try {
            if (
                    p.getCoefficient(0) != 4 ||
                    p.getCoefficient(1) != 6 ||
                    p.getCoefficient(2) != 3
                    ) {
                cout << "increment/Decrement Test Failed" << endl;
                return;
            }
        } catch (PolynomialException &e) {}

    }

    cout << "increment/Decrement Test Passed" << endl;
}

void correctIndexTest() {
    double array[3] = {4, 6, 3};
    unsigned int len = 3;
    Polynomial p(array, len);
    if (
            p[0] != 4 ||
            p[1] != 6 ||
            p[2] != 3
            ) {
        cout << "correct Index Test Failed" << endl;
        return;
    }

    cout << "correct Index Test Passed" << endl;
}

void inCorrectIndexTest() {
    double array[3] = {4, 6, 3};
    unsigned int len = 3;
    Polynomial p(array, len);
    try {
        p[3];
        cout << "inCorrect Index Failed" << endl;
        return;
    } catch (PolynomialException &e) {}


    cout << "inCorrect Index Passed" << endl;
}

void assignmentCorrectTest() {
    double array[5] = {4, 6, 3};
    unsigned int len = 5;
    Polynomial p(array, len);
    p = "1+2x^1+3x^5";
    if (
            p[0] != 1 ||
            p[1] != 2 ||
            p[2] != 0 ||
            p[3] != 0 ||
            p[5] != 3) {
        cout << "assignment Correct Test Failed" << endl;
        return;
    }
    cout << "assignment Correct Test Passed" << endl;
}