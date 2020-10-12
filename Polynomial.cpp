//
// Created by Victor on 18.09.2020.
//

#include "Polynomial.h"

//#include <mem.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>

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
    count++;
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

Polynomial Polynomial::operator+(Polynomial &p) {
    unsigned int order = std::max(p.order, this->order);
    Polynomial polynomial(order);
    memcpy(polynomial.coefficients, this->coefficients, this->order * sizeof(double));
    for (int i = 0; i < this->order; ++i) {
        polynomial.coefficients[i] += p.coefficients[i];
    }
    if (p.order > this->order) {
        for (int i = 0; i < p.order - this->order; ++i) {
            polynomial.coefficients[this->order + i] += p.coefficients[this->order + i];
        }
    }
    return std::move(polynomial);
}

Polynomial::Polynomial(const Polynomial &p) : order(p.getOrder()) {
    this->coefficients = new double[order];
    memcpy(this->coefficients, p.coefficients, order * sizeof(double));
    count++;
}

Polynomial::Polynomial(unsigned int m_order) : order(m_order) {
    coefficients = new double[order * sizeof(double)];
    count++;
}

Polynomial Polynomial::operator-(Polynomial &p) {
    unsigned int order = std::max(p.order, this->order);
    Polynomial polynomial(order);
    memset(polynomial.coefficients, 0, order * sizeof(double));
    memcpy(polynomial.coefficients, this->coefficients, this->order * sizeof(double));
    for (int i = 0; i < this->order; ++i) {
        polynomial.coefficients[i] -= p.coefficients[i];
    }
    if (p.order > this->order) {

        for (int i = 0; i < p.order - this->order; ++i) {

            polynomial.coefficients[this->order + i] -= p.coefficients[this->order + i];
        }
    }
    return std::move(polynomial);
}

double Polynomial::operator()(double x) {
    return getValue(x);
}

const Polynomial Polynomial::operator++(int) {
    Polynomial temp = *this;
    this->order++;
    this->coefficients = (double*) realloc(this->coefficients, this->order * sizeof(double));
    return temp;
}

const Polynomial Polynomial::operator--(int) {
    Polynomial temp = *this;
    this->order--;
    this->coefficients = (double*) realloc(this->coefficients, this->order * sizeof(double));
    return temp;
}

double Polynomial::operator[](unsigned int i) {
    return getCoefficient(i);
}

Polynomial &Polynomial::operator=(const char* str) {
    auto* coefficients = new double[this->order];
    memset(coefficients, 0, this->order * sizeof(double));
    unsigned int size = this->order;
    for (int i = 0; i < strlen(str);) {
        double coef;
        unsigned int order;
        int len;
        int err = sscanf(str + i, "%lgx^%u%n", &coef, &order, &len);
        if (err != 2) {
            err = sscanf(str + i, "%lg%n", &coef, &len);
            if (err != 1) {
                throw PolynomialException("Inccorect format");
            }
            order = 0;
        }


        if (order >= size) {
            size = order + 1;
            coefficients = (double*) realloc(coefficients, size * sizeof(double));
        }
        coefficients[order] += coef;
        i += len;
    }

    delete[] this->coefficients;
    this->coefficients = coefficients;
    this->order = size;

    return *this;
}

Polynomial::Polynomial(Polynomial &&other) noexcept {
    this->coefficients = other.coefficients;
    other.coefficients = nullptr;
    this->order = other.order;
    count++;
}

Polynomial &Polynomial::operator++() {
    this->order++;
    this->coefficients = (double*) realloc(this->coefficients, this->order * sizeof(double));
    return *this;
}

Polynomial &Polynomial::operator--() {
    this->order--;
    this->coefficients = (double*) realloc(this->coefficients, this->order * sizeof(double));
    return *this;
}

