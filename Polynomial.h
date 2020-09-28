//
// Created by Victor on 18.09.2020.
//

#ifndef LABS2_POLYNOMIAL_H
#define LABS2_POLYNOMIAL_H

#include <vector>
#include <string>

class Polynomial {
private:
    double* coefficients;
    unsigned int order;

    explicit Polynomial(unsigned int m_order);
public:
    explicit Polynomial(std::vector<double> &vec);

    Polynomial(double* coefficients, unsigned int order);

    Polynomial(const Polynomial &p);

    ~Polynomial();

    double getValue(double x) const;

    unsigned int getOrder() const { return order; };

    double getCoefficient(unsigned int order) const;

    void setCoefficient(double coefficient, unsigned int order);

    std::string toString() const;

    Polynomial operator+(Polynomial &p);

    Polynomial operator-(Polynomial &p);

    double operator()(double x);

    const Polynomial operator++(int);

    const Polynomial operator--(int);

    double operator[](unsigned int i);

    friend std::ostream &operator<<(std::ostream &Str, Polynomial const &poly) {
        // print something from v to str, e.g: Str << v.getX();
        Str << poly.toString();
        return Str;
    }
};

//CopyPaste from stackoverflow
class PolynomialException : public std::exception {
public:
    explicit PolynomialException(std::string msg)
            : msg_(std::move(msg)) {}

    ~PolynomialException() noexcept override = default;

    const char* what() const noexcept override {
        return msg_.c_str();
    }

private:
    std::string msg_;
};

#endif //LABS2_POLYNOMIAL_H
