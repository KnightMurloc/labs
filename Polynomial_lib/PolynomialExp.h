//
// Created by Victor on 09.11.2020.
//

#ifndef LABS2_POLYNOMIALEXP_H
#define LABS2_POLYNOMIALEXP_H

#include "Polynomial.h"

class PolynomialExp : public Polynomial {
public:
    PolynomialExp(double* coefficients, unsigned int order);
    PolynomialExp(double* coefficients,int* exps, unsigned int order);

    PolynomialExp(const Polynomial &p);

    double getValue(double x) const override;

    PolynomialExp &operator++();

    const PolynomialExp operator++(int i);

    PolynomialExp &operator=(const char* str);

    PolynomialExp &operator--();

    int GetExp(unsigned int idx);

protected:
    void setFromString(const char* str) override;

public:

    const PolynomialExp operator--(int i);

    char* toString() const override;

    ~PolynomialExp() override;

    PolynomialExp();

    PolynomialExp(Polynomial &&other);

private:
    int* coefExp;
};


#endif //LABS2_POLYNOMIALEXP_H
