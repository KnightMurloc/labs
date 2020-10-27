//
// Created by Victor on 18.09.2020.
//

#include "test.h"

#include "../Polynomial.h"
#include <iostream>
#include <cstring>

using namespace std;

//проверка коректности создания объекта с коректными данными
void createCorrectTest() {
    {
        double array[5] = {4, 6, 3, 7, 6};
        unsigned int len = 5;
        Polynomial polynomial(array, len);

        if (
                polynomial.getCoefficient(0) != 4 ||
                polynomial.getCoefficient(1) != 6 ||
                polynomial.getCoefficient(2) != 3 ||
                polynomial.getCoefficient(3) != 7 ||
                polynomial.getCoefficient(4) != 6
                ) {
            cout << "create correct test Failed" << endl;
        }
    }
    cout << "create correct test Passed" << endl;
}

//проверка обработки ошибки при создании объекта с некоректными параметрами
void createIncorrectTest() {

    try {
        double* array = nullptr;
        unsigned int len = 3;
        Polynomial polynomial(array, len);
        cout << "create incorrect test Failed" << endl;
    } catch (PolynomialException &e) {}

    try {
        auto* array = new double[4];
        unsigned int len = 0;
        Polynomial polynomial(array, len);
        cout << "create incorrect test Failed" << endl;
    } catch (PolynomialException &e) {}

    cout << "create incorrect test Passed" << endl;
}

//проверка вычисления значения функции в заданой точки
void getValueTest() {
    double array[] = {2, 5, 7};
    unsigned int len = 3;
    Polynomial polynomial(array, len);

    if (polynomial.getValue(2) == 40) {
        cout << "get Value test Passed" << endl;
    } else {
        cout << "get Value test Failed" << endl;
    }
}

//провека получения коофицентов объекта при при никоректных аргументах
void getIncorrectCoefficientTest() {
    try {
        double array[] = {2, 5, 7};
        unsigned int len = 3;
        Polynomial polynomial(array, len);
        polynomial.getCoefficient(100);
        cout << "get Incorrect Coefficient Test Failed" << endl;
    } catch (PolynomialException &e) {}
    cout << "get Incorrect Coefficient Test Passed" << endl;
}

//проверка установки коофицентов с коректными аргументами
void setCorrectCoefficientTest() {
    double array[] = {2, 5, 7};
    unsigned int len = 3;
    Polynomial polynomial(array, len);
    polynomial.setCoefficient(10, 0);
    polynomial.setCoefficient(16, 1);
    polynomial.setCoefficient(17, 2);
    if (
            polynomial.getCoefficient(0) == 10 ||
            polynomial.getCoefficient(1) == 16 ||
            polynomial.getCoefficient(2) == 17
            ) {
        cout << "set Correct Coefficient Test Passed" << endl;
        return;
    }
    cout << "set Correct Coefficient Test Failed" << endl;
}

//проверка установки коофицентов с не коректными аргументами
void setIncorrectCoefficientTest() {
    double array[] = {2, 5, 7};
    unsigned int len = 3;
    Polynomial polynomial(array, len);
    try {
        polynomial.setCoefficient(10, 200);
        cout << "set Incorrect Coefficient Test Failed" << endl;
    } catch (PolynomialException &e) {}
    cout << "set Incorrect Coefficient Passed" << endl;
}

//проверка приобразования объекта к строке
void toStringTest() {
    double array[] = {2, -5, 7.654};
    unsigned int len = 3;
    Polynomial p(array, len);

    if (strcmp(p.toString(), "2-5x^1+7.654x^2") == 0) {
        cout << "toString Test Passed" << endl;
    } else {
        cout << "toString Test Failed" << endl;
    }
}