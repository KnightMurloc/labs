//
// Created by Victor on 08.11.2020.
//

#ifndef LABS2_POLYNOMIALSTRING_H
#define LABS2_POLYNOMIALSTRING_H

#include "Polynomial.h"

class PolynomialString : public Polynomial {
public:
    PolynomialString(const char* str);

    PolynomialString(double* coefficients, unsigned int order);

    PolynomialString(const Polynomial &p);
    PolynomialString(const PolynomialString &p);

    ~PolynomialString() override;

    PolynomialString &operator++();

    const PolynomialString operator++(int i);

    PolynomialString &operator--();

    const PolynomialString operator--(int i);

    void setCoefficient(double coefficient, unsigned int order) override;

    PolynomialString &operator=(const char* str) override;

    [[nodiscard]] char* toString() const override;
private:
    char* str;
};


#endif //LABS2_POLYNOMIALSTRING_H
