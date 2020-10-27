//
// Created by Victor on 18.09.2020.
//

#ifndef LABS2_POLYNOMIAL_H
#define LABS2_POLYNOMIAL_H

#include <exception>
#include <iostream>
#include <sstream>

class Polynomial {
public:

    Polynomial();

    Polynomial(double* coefficients, unsigned int order);

    Polynomial(const Polynomial &p);

    Polynomial(Polynomial &&other) noexcept;

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

    Polynomial &operator++();
    const Polynomial operator++(int);

    Polynomial &operator--();
    const Polynomial operator--(int);

    double operator[](unsigned int i);

    Polynomial &operator=(const char* str);

    static unsigned int getCount() { return count; }

    friend std::ostream &operator<<(std::ostream &stream, Polynomial &p);

    friend std::istream &operator>>(std::istream &stream, Polynomial &p);

    friend std::ofstream &operator<<(std::ofstream &stream, Polynomial &p);

    friend std::ifstream &operator>>(std::ifstream &stream, Polynomial &p);

//    friend std::istringstream&operator<<(std::istringstream& stream,Polynomial& p);
//    friend std::istringstream&operator>>(std::istringstream& stream,Polynomial& p);

//    friend void operator<<(std::stringstream& stream,Polynomial& p);

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
