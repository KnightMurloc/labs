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
#include <fstream>
#include <sys/stat.h>

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
    int i = 0;
    if (getCoefficient(0) != 0) {
        i = sprintf(str, "%.20g", getCoefficient(0));
    }
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

Polynomial::Polynomial(const Polynomial &p) : order(p.getOrder()) {
    this->coefficients = new double[order];
    memcpy(this->coefficients, p.coefficients, order * sizeof(double));
    count++;
}

Polynomial::Polynomial(unsigned int m_order) : order(m_order) {
    coefficients = new double[order * sizeof(double)];
    count++;
}

double Polynomial::operator()(double x) {
    return getValue(x);
}

const Polynomial Polynomial::operator++(int) {
    Polynomial temp = *this;
    this->order++;
    this->coefficients = (double*) realloc(this->coefficients, this->order * sizeof(double));
    this->coefficients[order - 1] = 0;
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

    setFromString(str);

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

std::ostream &operator<<(std::ostream &stream, Polynomial &p) {
    char* str = p.toString();
    stream << str;
    delete str;
    return stream;
}

std::istream &operator>>(std::istream &stream, Polynomial &p) {
    char* str = new char[1024];
    unsigned int size = 1024;
    unsigned int i = 0;
    char c = stream.get();
    while (c != ' ' && c != -1) {
        if (i >= size) {
            size += 1024;
            str = (char*) realloc(str, size);
        }
        str[i++] = c;
        if (!stream.eof()) {
            c = stream.get();
        }
    }
    p = str;
    delete[] str;

    return stream;
}

std::ofstream &operator<<(std::ofstream &stream, Polynomial &p) {

    if (stream.flags() & std::ios::binary) {
        stream.write((char*) &p.order, sizeof(unsigned int));
        stream.write((char*) p.coefficients, p.order * sizeof(double));
    } else {
        stream << p.toString() << " ";
    }

    return stream;
}

std::ifstream &operator>>(std::ifstream &stream, Polynomial &p) {

    if (stream.flags() & std::ios::binary) {
        stream.read((char*) &p.order, sizeof(p.order));
        p.coefficients = new double[p.order];
        stream.read((char*) p.coefficients, p.order * sizeof(double));
    } else {
        unsigned int size = 0;
        unsigned int pos = stream.tellg();
        while (!stream.eof()) {
            if (stream.get() == ' ') {
                break;
            }
            size++;
        }
        stream.seekg(pos, std::ios::beg);
        char* str = new char[size + 1];
        str[size] = 0;
        stream >> str;
        stream.get();
        p = str;
        delete[] str;
    }

    return stream;
}

Polynomial::Polynomial() {
    coefficients = new double(0);
    order = 1;
    count++;
}

void Polynomial::setFromString(const char* str) {
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
            unsigned int old_size = size;
            size = order + 1;
            coefficients = (double*) realloc(coefficients, size * sizeof(double));
//            memset(coefficients + old_size, 0, order - old_size - 1);
//            memset(coefficients + old_size,0,size - old_size + 1);
            for (int j = old_size; j <= size - old_size + 1; ++j) {
//                printf("%lf\n",coefficients[j]);
                coefficients[j] = 0;
            }
            coefficients[order] = 0;
        }
//        printf("%lf\n",coefficients[order]);
        coefficients[order] += coef;
        i += len;
    }

    delete[] this->coefficients;
    this->coefficients = coefficients;
    this->order = size;
}

Polynomial operator+(Polynomial &p1, Polynomial &p2) {
    unsigned int order = std::max(p2.order, p2.order);
    Polynomial polynomial(order);
    memset(polynomial.coefficients,0,polynomial.order * sizeof(double));
    memcpy(polynomial.coefficients, p1.coefficients, p1.order * sizeof(double));
    for (unsigned int i = 0; i < p1.order; ++i) {
        polynomial.coefficients[i] += p2.coefficients[i];
    }
    if (p2.order > p1.order) {
        for (unsigned int i = 0; i < p2.order - p1.order; ++i) {
            polynomial.coefficients[p1.order + i] += p2.coefficients[p1.order + i];
        }
    }
    return std::move(polynomial);
}

Polynomial operator-(Polynomial &p1, Polynomial &p2) {
    unsigned int order = std::max(p2.order, p1.order);
    Polynomial polynomial(order);
    memset(polynomial.coefficients, 0, order * sizeof(double));
    memcpy(polynomial.coefficients, p1.coefficients, p1.order * sizeof(double));
    for (int i = 0; i < p1.order; ++i) {
        polynomial.coefficients[i] -= p2.coefficients[i];
    }
    if (p2.order > p1.order) {

        for (int i = 0; i < p2.order - p1.order; ++i) {

            polynomial.coefficients[p1.order + i] -= p2.coefficients[p1.order + i];
        }
    }
    return std::move(polynomial);
}

double* Polynomial::getCoefficients() {
    return coefficients;
}

//void operator<<(std::stringstream& stream, Polynomial& p) {
//    char* str = p.toString();
//    stream << str;
//    delete [] str;
//}

//std::ostringstream &operator<<(std::ostringstream &stream, Polynomial &p) {
//    char* str = p.toString();
//    stream << str;
//    delete [] str;
//
//    return stream;
//}
//
//std::istringstream &operator<<(std::istringstream &stream, Polynomial &p) {
//    char data[1024];
//    char* str = new char[sizeof(data)];
//    unsigned int size = sizeof(data);
//    bool is_have_zero = false;
//    do {
//        stream.getline(data, sizeof(data));
//        memcpy(str + size - sizeof(data),data,sizeof(data));
//        for (char i : data) {
//            if(i == 0){
//                is_have_zero = true;
//                break;
//            }
//        }
//
//        if(!is_have_zero){
//            str = (char*) realloc(str, size += 1024);
//        }
//
//    }while(!is_have_zero);
//
//    p = str;
//    delete[] str;
//
//    return stream;
//}

