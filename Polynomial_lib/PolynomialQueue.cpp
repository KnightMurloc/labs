//
// Created by Victor on 23.11.2020.
//

#include "PolynomialQueue.h"
#include <iostream>

PolynomialQueue::PolynomialQueue() {
    frist = new Node();
    last = frist;
    frist->prev = last;
    last->next = frist;
}

PolynomialQueue::~PolynomialQueue() {
    Node* current = frist->next;
    while(current != frist){
        Node* temp = current;
        current = current->next;
        delete temp->data;
        delete temp;
    }
}


void PolynomialQueue::push(Polynomial* polynomial) {
    Node* temp = frist;
//    frist = new Node();
//    temp->data = polynomial;
//    frist->next = temp;
//    temp->next = frist;
//    frist->prev = temp;

    frist = new Node();
    temp->data = polynomial;
    frist->next = temp;
    temp->prev = frist;

    frist->prev = last;
    last->next = frist;
}

Polynomial* PolynomialQueue::pop() {
    if(last->data == nullptr){
        throw PolynomialQueueException("Out of Range Array");
    }
    Polynomial* result = last->data;
    Node* temp = last;
    last = temp->prev;
    delete temp;

    frist->prev = last;
    last->next = frist;

    return result;
}

std::ostream &operator<<(std::ostream &stream, PolynomialQueue &p) {
    PolynomialQueue::Node* current = p.frist->next;
    while(current != p.frist){
        stream << current->data->toString() << std::endl;
        current = current->next;
    }

    return stream;
}

void PolynomialQueue::insert(Polynomial* p, unsigned int idx) {
    Node* current = frist->next;
    for (int i = 0; i < idx & current != frist; ++i) {
        current = current->next;
    }
    if(current == frist){
        throw PolynomialException("Index out of range");
    }
    current = current->prev;
    Node* temp = current->next;
    current->next = new Node();
    current->next->data = p;
    current->next->prev = current;
    current->next->next = temp;
    temp->prev = current->next;

    frist->prev = last;
    last->next = frist;
}

void PolynomialQueue::remove(unsigned int idx) {
    Node* current = frist->next;
    for (int i = 0; i < idx & current != frist; ++i) {
        current = current->next;
    }
    if(current == frist){
        throw PolynomialException("Index out of range");
    }

    Node* prev = current->prev;
    Node* next = current->next;

    prev->next = next;
    next->prev = prev;

    delete current->data;
    delete current;
}

Polynomial* PolynomialQueue::get(unsigned int idx) {
    Node* current = frist->next;
    for (int i = 0; i < idx & current != frist; ++i) {
        current = current->next;
    }
    if(current == frist){
        throw PolynomialQueueException("Out of Range Array");
    }

    return current->data;
}
