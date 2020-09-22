//
// Created by Victor on 18.09.2020.
//

#include "test.h"

#include "../Polynomial.h"
#include <vector>
#include <iostream>

using namespace std;

//проверка коректности создания объекта с коректными данными
void createCorrectTest() {
    {
        vector<double> vec = {2, 5, 7};
        Polynomial polynomial(vec);
        if (
                polynomial.getCoefficient(0) != 2 ||
                polynomial.getCoefficient(1) != 5 ||
                polynomial.getCoefficient(2) != 7
                ) {
            cout << "create correct test Failed" << endl;
        }
    }

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
        vector<double> vec;
        Polynomial polynomial(vec);
        cout << "create incorrect test Failed" << endl;
    } catch (PolynomialException &e) {}

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
    vector<double> vec = {2, 5, 7};
    Polynomial polynomial(vec);

    if (polynomial.getValue(2) == 40) {
        cout << "get Value test Passed" << endl;
    } else {
        cout << "get Value test Failed" << endl;
    }
}

//провека получения коофицентов объекта при при никоректных аргументах
void getIncorrectCoefficientTest() {
    try {
        vector<double> vec = {2, 5, 7};
        Polynomial polynomial(vec);
        polynomial.getCoefficient(100);
        cout << "get Incorrect Coefficient Test Failed" << endl;
    } catch (PolynomialException &e) {}
    cout << "get Incorrect Coefficient Test Passed" << endl;
}

//проверка установки коофицентов с коректными аргументами
void setCorrectCoefficientTest() {
    vector<double> vec = {2, 5, 7};
    Polynomial polynomial(vec);
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
    vector<double> vec = {2, 5, 7};
    Polynomial polynomial(vec);
    try {
        polynomial.setCoefficient(10, 200);
        cout << "set Incorrect Coefficient Test Failed" << endl;
    } catch (PolynomialException &e) {}
    cout << "set Incorrect Coefficient Passed" << endl;
}

//проверка приобразования объекта к строке
void toStringTest() {
    vector<double> vec = {2, 5, 7};
    Polynomial polynomial(vec);

    if (polynomial.toString() == "2+5x^1+7x^2") {
        cout << "toString Test Passed" << endl;
    } else {
        cout << "toString Test Failed" << endl;
    }
}