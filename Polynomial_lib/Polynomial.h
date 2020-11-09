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

    virtual ~Polynomial();

    virtual //double Polynomial::getValue(double x)
    //вычилсяет значение функции в точке x
    //arcs:
    // - int x - точка на прямой
    //return - занчение в точке
    double getValue(double x) const;

    [[nodiscard]] unsigned int getOrder() const { return order; };

    //double Polynomial::getCoefficient(int order)
    //возвращаяет коофицкнт определёного порядка
    //args:
    // - unsigned int order - порядок коофицента
    //return - коофицент
    double getCoefficient(unsigned int order) const;

    virtual //void Polynomial::setCoefficient(double coefficient, int order)
    //задаёт коофицент лпределёного порядка
    //args:
    // - double coefficient - значение коофицента
    // - unsigned int order - порядок коофицента
    void setCoefficient(double coefficient, unsigned int order);

     //char* Polynomial::toString()
    //приобразует объект к строке
    //return - строка
    [[nodiscard]] virtual char* toString() const;

    friend Polynomial operator+(Polynomial &p1,Polynomial &p2);

    friend Polynomial operator-(Polynomial &p1,Polynomial &p2);

    virtual double operator()(double x);

    virtual Polynomial &operator++();

    const Polynomial operator++(int);

    virtual Polynomial &operator--();

    const Polynomial operator--(int);

    double operator[](unsigned int i);

    virtual Polynomial &operator=(const char* str);

    static unsigned int getCount() { return count; }

    friend std::ostream &operator<<(std::ostream &stream, Polynomial &p);

    friend std::istream &operator>>(std::istream &stream, Polynomial &p);

    friend std::ofstream &operator<<(std::ofstream &stream, Polynomial &p);

    friend std::ifstream &operator>>(std::ifstream &stream, Polynomial &p);

    explicit Polynomial(unsigned int order);

    double* getCoefficients();
protected:
    virtual void setFromString(const char* str);
    static unsigned int count;
    double* coefficients;

    unsigned int order;


};

//CopyPaste from stackoverflow
class PolynomialException : public std::exception {
public:
    explicit PolynomialException(const char* msg)
            : msg_(msg) {}

    ~PolynomialException() noexcept override = default;

    [[nodiscard]] const char* what() const noexcept override {
        return msg_;
    }

private:
    const char* msg_;
};

#endif //LABS2_POLYNOMIAL_H
