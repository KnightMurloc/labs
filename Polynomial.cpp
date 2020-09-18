//
// Created by Victor on 18.09.2020.
//

#include "Polynomial.h"

#include <mem.h>
#include <cmath>

Polynomial::Polynomial(std::vector<double> vec) {
    coefficients = new double[vec.size()];
    memcpy(coefficients, vec.data(), vec.size() * sizeof(double));
    order = (int) vec.size();
}

Polynomial::~Polynomial() {
    delete[] coefficients;
}

Polynomial::Polynomial(double* coefficients, unsigned int order) {
    this->order = order;
    coefficients = new double[order];
    memcpy(coefficients, coefficients, order * sizeof(double));
}

//double Polynomial::getValue(double x)
//вычилсяет значение функции в точке x
//arcs:
// - int x - точка на прямой
//return - занчение в точке
double Polynomial::getValue(double x) {
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