//
// Created by Victor on 18.09.2020.
//

#ifndef LABS2_POLYNOMIAL_H
#define LABS2_POLYNOMIAL_H

#include <exception>

class Polynomial {
public:
    Polynomial(double* coefficients, unsigned int order);

    Polynomial(const Polynomial &p);

    ~Polynomial();

    //double Polynomial::getValue(double x)
    //вычилсяет значение функции в точке x
    //arcs:
    // - int x - точка на прямой
    //return - занчение в точке
    double getValue(double x) const;

    unsigned int getOrder() const { return order; };

    //double Polynomial::getCoefficient(int order)
    //возвращаяет коофицкнт определёного порядка
    //args:
    // - unsigned int order - порядок коофицента
    //return - коофицент
    double getCoefficient(unsigned int order) const;

    //void Polynomial::setCoefficient(double coefficient, int order)
    //задаёт коофицент лпределёного порядка
    //args:
    // - double coefficient - значение коофицента
    // - unsigned int order - порядок коофицента
    void setCoefficient(double coefficient, unsigned int order);

    //char* Polynomial::toString()
    //приобразует объект к строке
    //return - строка
    char* toString() const;

    Polynomial operator+(Polynomial &p);

    Polynomial operator-(Polynomial &p);

    double operator()(double x);

    const Polynomial operator++(int);

    const Polynomial operator--(int);

    double operator[](unsigned int i);

    Polynomial &operator=(const char* str);

    static unsigned int getCount() { return count; }

private:
    static unsigned int count;
    double* coefficients;
    unsigned int order;

    explicit Polynomial(unsigned int order);
};

//CopyPaste from stackoverflow
class PolynomialException : public std::exception {
public:
    explicit PolynomialException(const char* msg)
            : msg_(msg) {}

    ~PolynomialException() noexcept override = default;

    const char* what() const noexcept override {
        return msg_;
    }

private:
    const char* msg_;
};

#endif //LABS2_POLYNOMIAL_H
