//
// Created by Victor on 08.11.2020.
//

#include "PolynomialString.h"
#include <cstring>


PolynomialString::PolynomialString(const char* str) {
//    this->coefficients = nullptr;
    this->order = 1;
    this->str = strdup(str);
    setFromString(str);
}

PolynomialString::PolynomialString(double* coefficients, unsigned int order) : Polynomial(
        coefficients, order) {
    this->str = Polynomial::toString();
}

void PolynomialString::setCoefficient(double coefficient, unsigned int order) {
    Polynomial::setCoefficient(coefficient, order);
    this->str = Polynomial::toString();
}

char* PolynomialString::toString() const {
    return str;
}

PolynomialString &PolynomialString::operator++() {
    this->order++;
    this->coefficients = (double*) realloc(this->coefficients, this->order * sizeof(double));
    str = Polynomial::toString();
    return *this;
}

const PolynomialString PolynomialString::operator++(int) {
    PolynomialString temp = *this;
    this->order++;
    this->coefficients = (double*) realloc(this->coefficients, this->order * sizeof(double));
    this->coefficients[order - 1] = 0;
    this->str = Polynomial::toString();

    return temp;
}

PolynomialString &PolynomialString::operator--() {
    this->order--;
    this->coefficients = (double*) realloc(this->coefficients, this->order * sizeof(double));
    this->str = Polynomial::toString();
    return *this;
}

const PolynomialString PolynomialString::operator--(int i) {
    PolynomialString temp = *this;
    this->order--;
    this->coefficients = (double*) realloc(this->coefficients, this->order * sizeof(double));
    this->str = Polynomial::toString();
    return temp;
}

PolynomialString &PolynomialString::operator=(const char* str) {
    setFromString(str);
    this->str = strdup(str);
    return *this;
}

PolynomialString::PolynomialString(const Polynomial &p) : Polynomial(p) {
    str = p.toString();
}

PolynomialString::~PolynomialString() {
    delete [] str;
}

PolynomialString::PolynomialString(const PolynomialString &p) {
    this->order = p.order;
    this->coefficients = new double[order];
    memcpy(this->coefficients, p.coefficients, order * sizeof(double));
    this->str = Polynomial::toString();
    count++;
}
