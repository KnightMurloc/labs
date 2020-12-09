//
// Created by Victor on 23.11.2020.
//

#ifndef LABS2_POLYNOMIALQUEUE_H
#define LABS2_POLYNOMIALQUEUE_H

#include "Polynomial.h"
#include "List.h"

class PolynomialQueue : public List<Polynomial*> {
private:
    class Node{
        friend PolynomialQueue;
    public:
        Polynomial* data = nullptr;
        Node* next = nullptr;
        Node* prev = nullptr;
        friend std::ostream &operator<<(std::ostream &stream, PolynomialQueue &p);
    };

public:
    Node* frist;

    Polynomial* get(unsigned int idx) override;

    Node* last;
    PolynomialQueue();
    ~PolynomialQueue();

    void push(Polynomial* polynomial) override;
    void insert(Polynomial* polynomial, unsigned int idx) override;
    void remove(unsigned int idx) override;

    Polynomial* pop() override;

    friend std::ostream &operator<<(std::ostream &stream, PolynomialQueue &p);
};

class PolynomialQueueException : public std::exception {
public:
    explicit PolynomialQueueException(const char* msg)
            : msg_(msg) {}

    ~PolynomialQueueException() noexcept override = default;

    [[nodiscard]] const char* what() const noexcept override {
        return msg_;
    }

private:
    const char* msg_;
};
#endif //LABS2_POLYNOMIALQUEUE_H
