//
// Created by Victor on 18.09.2020.
//

#include "Polynomial.h"

//#include <mem.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

unsigned int Polynomial::count = 0;

Polynomial::~Polynomial() {
    delete[] coefficients;
    count--;
}

Polynomial::Polynomial(double* coefficients, unsigned int order) {
    if (coefficients == nullptr) {
        throw PolynomialException("coefficients is null");
    }

    if (order == 0) {
        throw PolynomialException("coefficients is empty");
    }

    this->order = order;
    this->coefficients = new double[order];
    memcpy(this->coefficients, coefficients, order * sizeof(double));
}


double Polynomial::getValue(double x) const {
    double result = 0;
    for (int i = 0; i < order; ++i) {
        result += coefficients[i] * pow(x, i);
    }
    return result;
}

char* Polynomial::toString() const {
    //39 максимальное число символов необходимое для записи многочлена
    //24 - максимальная длина double
    //10 - максимальная длина uint
    //3 - +-x^
    //1 - \0
    auto str = (char*) malloc(37 * getOrder() + 1);
    memset(str, 0, 25 * getOrder() + 1);
    int i = sprintf(str, "%.20g", getCoefficient(0));
    for (unsigned int j = 1; j < getOrder(); j++) {
        if (getCoefficient(j) > 0) {
            i += sprintf(str + i, "+%gx^%d", getCoefficient(j), j);
        } else if (getCoefficient(j) < 0) {
            i += sprintf(str + i, "%gx^%d", getCoefficient(j), j);
        }
    }
    str = (char*) realloc(str, (size_t) i + 1);

    return str;
}


double Polynomial::getCoefficient(unsigned int order) const {
    if (order >= this->order) {
        throw PolynomialException("Out of Range Array");
    }
    return coefficients[order];
}


void Polynomial::setCoefficient(double coefficient, unsigned int order) {
    if (order >= this->order) {
        throw PolynomialException("Out of Range Array");
    }
    coefficients[order] = coefficient;
}
