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

//    explicit PolynomialExp(const Polynomial &p);
    PolynomialExp(const PolynomialExp &p);

    [[nodiscard]] double getValue(double x) const override;

    PolynomialExp &operator++() override;

    const PolynomialExp operator++(int);

    PolynomialExp &operator=(const char* str) override;

    PolynomialExp &operator--() override;

    int getExp(unsigned int idx);

    double operator()(double x) override;

    const PolynomialExp operator--(int i);

    [[nodiscard]] char* toString() const override;

    ~PolynomialExp() override;

    PolynomialExp();

    friend Polynomial operator+(Polynomial& p1,PolynomialExp& p2);
    friend Polynomial operator+(PolynomialExp& p1,PolynomialExp& p2);
    friend Polynomial operator+(PolynomialExp& p1,Polynomial& p2);

    friend Polynomial operator-(Polynomial& p1,PolynomialExp& p2);
    friend Polynomial operator-(PolynomialExp& p1,PolynomialExp& p2);
    friend Polynomial operator-(PolynomialExp& p1,Polynomial& p2);

    explicit PolynomialExp(Polynomial &&other);

    explicit operator Polynomial() const;
protected:
    void setFromString(const char* str) override;

private:
    int* coefExp;
};


#endif //LABS2_POLYNOMIALEXP_H
