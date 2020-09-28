//
// Created by Victor on 18.09.2020.
//

#include "Polynomial.h"

#include <mem.h>
#include <cmath>

Polynomial::Polynomial(std::vector<double> &vec) {
    if (vec.empty()) {
        throw PolynomialException("vector is empty");
    }

    coefficients = new double[vec.size()];
    memcpy(coefficients, vec.data(), vec.size() * sizeof(double));
    order = (int) vec.size();
}

Polynomial::~Polynomial() {
    delete[] coefficients;
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

//double Polynomial::getValue(double x)
//вычилсяет значение функции в точке x
//arcs:
// - int x - точка на прямой
//return - занчение в точке
double Polynomial::getValue(double x) const {
    double result = 0;
    for (int i = 0; i < order; ++i) {
        result += coefficients[i] * pow(x, i);
    }
    return result;
}

//CopyPaste from stackoverflow
namespace util {
    template<typename T>
    std::string to_string(const T &t) {
        std::string str{std::to_string(t)};
        int offset{1};
        if (str.find_last_not_of('0') == str.find('.')) { offset = 0; }
        str.erase(str.find_last_not_of('0') + offset, std::string::npos);
        return str;
    }
}

//std::string Polynomial::toString()
//приобразует объект к строке
//return - строка
std::string Polynomial::toString() const {
    std::string str = util::to_string(coefficients[0]);
    for (int i = 1; i < order; ++i) {
        if (coefficients[i] > 0) {
            str += " + " + util::to_string(coefficients[i]) + "x^" + std::to_string(i);
        } else if (coefficients[i] < 0) {
            str += " - " + util::to_string(-coefficients[i]) + "x^" + std::to_string(i);
        }
    }
    return str;
}

//double Polynomial::getCoefficient(int order)
//возвращаяет коофицкнт определёного порядка
//args:
// - unsigned int order - порядок коофицента
//return - коофицент
double Polynomial::getCoefficient(unsigned int order) const {
    if (order >= this->order) {
        throw PolynomialException("Out of Range Array");
    }
    return coefficients[order];
}

//void Polynomial::setCoefficient(double coefficient, int order)
//задаёт коофицент лпределёного порядка
//args:
// - double coefficient - значение коофицента
// - unsigned int order - порядок коофицента
void Polynomial::setCoefficient(double coefficient, unsigned int order) {
    if (order >= this->order) {
        throw PolynomialException("Out of Range Array");
    }
    coefficients[order] = coefficient;
}

Polynomial Polynomial::operator+(Polynomial &p) {
    unsigned int order = p.order >= this->order ? p.order : this->order;
    Polynomial polynomial(order);
    memcpy(polynomial.coefficients, p.coefficients, p.order * sizeof(double));
    for (int i = 0; i < this->order; ++i) {
        polynomial.coefficients[i] += this->coefficients[i];
    }
    return polynomial;
}

Polynomial::Polynomial(const Polynomial &p) : order(p.getOrder()) {
    this->coefficients = new double[order];
    memcpy(this->coefficients, p.coefficients, order * sizeof(double));
}

Polynomial::Polynomial(unsigned int m_order) : order(m_order) {
    coefficients = new double[order * sizeof(double)];
}

Polynomial Polynomial::operator-(Polynomial &p) {
    unsigned int order = p.order >= this->order ? p.order : this->order;
    Polynomial polynomial(order);
    memcpy(polynomial.coefficients, p.coefficients, p.order * sizeof(double));
    for (int i = 0; i < this->order; ++i) {
        polynomial.coefficients[i] -= this->coefficients[i];
    }
    return polynomial;
}

double Polynomial::operator()(double x) {
    return getValue(x);
}

const Polynomial Polynomial::operator++(int) {
    Polynomial polynomial(this->order + 1);
    memcpy(polynomial.coefficients, this->coefficients, polynomial.order * sizeof(double));
    return polynomial;
}

const Polynomial Polynomial::operator--(int) {
    Polynomial polynomial(this->order - 1);
    memcpy(polynomial.coefficients, this->coefficients, polynomial.order * sizeof(double));
    return polynomial;
}

double Polynomial::operator[](unsigned int i) {
    return getCoefficient(i);
}
