//
// Created by Victor on 09.11.2020.
//

#include <memory.h>
#include <cmath>
#include <cstring>
#include "PolynomialExp.h"

PolynomialExp::PolynomialExp(double* coefficients, unsigned int order) : Polynomial(coefficients,
                                                                                    order) {
    coefExp = new int[order];
    memset(coefExp,1,order * sizeof(int));
}

PolynomialExp::PolynomialExp(double* coefficients, int* exps, unsigned int order) : PolynomialExp(coefficients,order) {
    if(exps == nullptr){
        throw PolynomialException("exps is null");
    }
    this->coefExp = new int[order];
    memcpy(this->coefExp, exps, order * sizeof(int));
}

PolynomialExp::PolynomialExp(const Polynomial &p) : Polynomial(p) {
    coefExp = new int[order];
    memset(coefExp,1,order * sizeof(int));
}

PolynomialExp::PolynomialExp(Polynomial &&other) : Polynomial(other) {
    coefExp = new int[order];
    memset(coefExp,1,order * sizeof(int));
}

PolynomialExp::PolynomialExp() : Polynomial() {
    coefExp = new int(1);
}

PolynomialExp::~PolynomialExp() {
//    delete [] coefficients;
    delete [] coefExp;
}

char* PolynomialExp::toString() const {
    //49 максимальное число символов необходимое для записи многочлена
    //24 - максимальная длина double
    //10 - максимальная длина uint
    //10 - максимальная длина uint
    //3 - +-x^
    //1 - \0
    printf("test\n");
    auto str = (char*) malloc(49 * getOrder() + 1);
    memset(str, 0, 49 * getOrder() + 1);
    int i = 0;
    if (getCoefficient(0) != 0) {
        i = sprintf(str, "%.20g", getCoefficient(0));
        if(coefExp[0] != 1){
            i += sprintf(str + i, "^%d",coefExp[0]);
        }
    }
    for (unsigned int j = 1; j < getOrder(); j++) {
        if (getCoefficient(j) > 0) {
            if(coefExp[j] != 1){
                i += sprintf(str + i, "+%g^%dx^%d", getCoefficient(j),coefExp[j], j);
            } else{
                i += sprintf(str + i, "+%gx^%d", getCoefficient(j), j);
            }
        } else if (getCoefficient(j) < 0) {
            if(coefExp[j] != 1){
                i += sprintf(str + i, "%g^%dx^%d", getCoefficient(j),coefExp[j], j);
            } else{
                i += sprintf(str + i, "%gx^%d", getCoefficient(j), j);
            }
        }
    }
//    str = (char*) realloc(str, (size_t) i + 1);

    return str;
}

double PolynomialExp::getValue(double x) const {
    double result = 0;
    for (int i = 0; i < order; ++i) {
        result += pow(coefficients[i],coefExp[i]) * pow(x, i);
    }
    return result;
}

PolynomialExp &PolynomialExp::operator++() {
    this->order++;
    this->coefficients = (double*) realloc(this->coefficients, this->order * sizeof(double));
    this->coefExp = (int*) realloc(this->coefExp,this->order * sizeof(int));
    return *this;
}

const PolynomialExp PolynomialExp::operator++(int i) {
    PolynomialExp temp = *this;
    this->order++;
    this->coefficients = (double*) realloc(this->coefficients, this->order * sizeof(double));
    this->coefExp = (int*) realloc(this->coefExp,this->order * sizeof(int));
    this->coefficients[order - 1] = 0;
    this->coefExp[order - 1] = 1;
    return temp;
}

PolynomialExp &PolynomialExp::operator--() {
    this->order--;
    this->coefficients = (double*) realloc(this->coefficients, this->order * sizeof(double));
    this->coefExp = (int*) realloc(this->coefExp,this->order * sizeof(int));
    return *this;
}

const PolynomialExp PolynomialExp::operator--(int i) {
    PolynomialExp temp = *this;
    this->order--;
    this->coefficients = (double*) realloc(this->coefficients, this->order * sizeof(double));
    this->coefExp = (int*) realloc(this->coefExp,this->order * sizeof(int));
    return temp;
}

void PolynomialExp::setFromString(const char* str) {
    auto* coefficients = new double[this->order];
    auto* coefExp = new int[this->order];
    memset(coefficients, 0, this->order * sizeof(double));
    unsigned int size = this->order;
    for (int i = 0; i < strlen(str);) {

        double coef;
        int exp = 1;
        unsigned int order;
        int len;
//        int err = sscanf(str + i, "%lgx^%u%n", &coef, &order, &len);
        int err = sscanf(str + i, "%lg^%dx^%u%n", &coef,&exp, &order, &len);
        if (err != 3) {
            err = sscanf(str + i, "%lgx^%u%n", &coef, &order, &len);
            if(err != 2){
                err = sscanf(str + i, "%lg^%d%n", &coef,&exp, &len);
                if (err != 2) {
                    err = sscanf(str + i, "%lg%n", &coef, &len);
                    if(err != 1) {
                        throw PolynomialException("Inccorect format");
                    }
                }
                order = 0;
            }
        }


        if (order >= size) {
            unsigned int old_size = size;
            size = order + 1;
            coefficients = (double*) realloc(coefficients, size * sizeof(double));
            coefExp = (int*) realloc(coefExp, size * sizeof(int));
//            memset(coefficients + old_size, 0, order - old_size - 1);
//            memset(coefficients + old_size,0,size - old_size + 1);
            for (int j = old_size; j <= size - old_size + 1; ++j) {
//                printf("%lf\n",coefficients[j]);
                coefficients[j] = 0;
                coefExp[j] = 1;
            }
            coefficients[order] = 0;
        }
//        printf("%lf\n",coefficients[order]);
        coefficients[order] += coef;
        coefExp[order] = exp;
        i += len;
    }

    delete[] this->coefficients;
    delete[] this->coefExp;
    this->coefficients = coefficients;
    this->coefExp = coefExp;
    this->order = size;
}

int PolynomialExp::getExp(unsigned int idx) {
    if(idx >= order){
        throw PolynomialException("Out of Range Array");
    }

    return coefExp[idx];
}

PolynomialExp &PolynomialExp::operator=(const char* str) {
    setFromString(str);
    return *this;
}

Polynomial operator+(Polynomial &p1, PolynomialExp& p2) {
    unsigned int order = std::max(p2.order, p2.order);
    Polynomial polynomial(order);
    memset(polynomial.getCoefficients(),0,polynomial.getOrder() * sizeof(double));
    memcpy(polynomial.getCoefficients(), p1.getCoefficients(), p1.getOrder() * sizeof(double));
    for (unsigned int i = 0; i < p1.getOrder(); ++i) {
        polynomial.getCoefficients()[i] += pow(p2.coefficients[i], p2.getExp(i));
    }
    if (p2.order > p1.getOrder()) {
        for (unsigned int i = 0; i < p2.order - p1.getOrder(); ++i) {
            polynomial.getCoefficients()[p1.getOrder() + i] += pow(p2.coefficients[p1.getOrder() + i],
                                                                   p2.getExp(i));
        }
    }
    return std::move(polynomial);
}

Polynomial operator+(PolynomialExp &p1, PolynomialExp &p2) {
    unsigned int order = std::max(p2.order, p2.order);
    Polynomial polynomial(order);
    memset(polynomial.getCoefficients(),0,polynomial.getOrder() * sizeof(double));
    for (int i = 0; i < p1.getOrder(); ++i) {
        polynomial.setCoefficient(pow(p1[i],p1.getExp(i)),i);
    }
    for (unsigned int i = 0; i < p1.order; ++i) {
        polynomial.getCoefficients()[i] += pow(p2[i],p2.getExp(i));
    }
    if (p2.order > p1.order) {
        for (unsigned int i = 0; i < p2.order - p1.order; ++i) {
            polynomial.getCoefficients()[p1.order + i] +=
                    pow(p2[p1.order + i],p2.getExp(p1.order + i));
        }
    }
    return std::move(polynomial);
}

Polynomial operator+(PolynomialExp &p1, Polynomial &p2) {
    unsigned int order = std::max(p2.getOrder(), p2.getOrder());
    Polynomial polynomial(order);
    memset(polynomial.getCoefficients(),0,polynomial.getOrder() * sizeof(double));
    for (int i = 0; i < p1.getOrder(); ++i) {
        polynomial.setCoefficient(pow(p1[i],p1.getExp(i)),i);
    }
    for (unsigned int i = 0; i < p1.order; ++i) {
        polynomial.getCoefficients()[i] += p2[i];
    }
    if (p2.getOrder() > p1.order) {
        for (unsigned int i = 0; i < p2.getOrder() - p1.order; ++i) {
            polynomial.getCoefficients()[p1.order + i] += p2[p1.order + i];
        }
    }
    return std::move(polynomial);
}

Polynomial operator-(Polynomial &p1, PolynomialExp& p2) {
    unsigned int order = std::max(p2.order, p2.order);
    Polynomial polynomial(order);
    memset(polynomial.getCoefficients(),0,polynomial.getOrder() * sizeof(double));
    memcpy(polynomial.getCoefficients(), p1.getCoefficients(), p1.getOrder() * sizeof(double));
    for (unsigned int i = 0; i < p1.getOrder(); ++i) {
        polynomial.getCoefficients()[i] -= pow(p2.coefficients[i], p2.getExp(i));
    }
    if (p2.order > p1.getOrder()) {
        for (unsigned int i = 0; i < p2.order - p1.getOrder(); ++i) {
            polynomial.getCoefficients()[p1.getOrder() + i] -= pow(p2.coefficients[p1.getOrder() + i],
                                                                   p2.getExp(i));
        }
    }
    return std::move(polynomial);
}

Polynomial operator-(PolynomialExp &p1, PolynomialExp &p2) {
    unsigned int order = std::max(p2.order, p2.order);
    Polynomial polynomial(order);
    memset(polynomial.getCoefficients(),0,polynomial.getOrder() * sizeof(double));
    for (int i = 0; i < p1.getOrder(); ++i) {
        polynomial.setCoefficient(pow(p1[i],p1.getExp(i)),i);
    }
    for (unsigned int i = 0; i < p1.order; ++i) {
        polynomial.getCoefficients()[i] -= pow(p2[i],p2.getExp(i));
    }
    if (p2.order > p1.order) {
        for (unsigned int i = 0; i < p2.order - p1.order; ++i) {
            polynomial.getCoefficients()[p1.order + i] -=
                    pow(p2[p1.order + i],p2.getExp(p1.order + i));
        }
    }
    return std::move(polynomial);
}

Polynomial operator-(PolynomialExp &p1, Polynomial &p2) {
    unsigned int order = std::max(p2.getOrder(), p2.getOrder());
    Polynomial polynomial(order);
    memset(polynomial.getCoefficients(),0,polynomial.getOrder() * sizeof(double));
    for (int i = 0; i < p1.getOrder(); ++i) {
        polynomial.setCoefficient(pow(p1[i],p1.getExp(i)),i);
    }
    for (unsigned int i = 0; i < p1.order; ++i) {
        polynomial.getCoefficients()[i] -= p2[i];
    }
    if (p2.getOrder() > p1.order) {
        for (unsigned int i = 0; i < p2.getOrder() - p1.order; ++i) {
            polynomial.getCoefficients()[p1.order + i] -= p2[p1.order + i];
        }
    }
    return std::move(polynomial);
}

PolynomialExp::operator Polynomial() const {
    auto* coef = new double[order];
    for (int i = 0; i < order; ++i) {
        coef[i] = pow(coefficients[i],coefExp[i]);
    }

    Polynomial p = Polynomial(coef,order);

    delete[] coef;
    printf("test\n");
    return std::move(p);
}
