//
// Created by Victor on 07.12.2020.
//

#include "Queue.h"

template<typename T>
T Queue<T>::get(unsigned int idx) {
    if(frist == nullptr){
        throw QueueException("Out of Range Array");
    }

    if(idx == 0){
        return frist->data;
    }

    Node* current = frist->next;
    for (int i = 1; i < idx & current != frist; ++i) {
        current = current->next;
    }
    if(current == frist){
        throw QueueException("Out of Range Array");
    }

    return current->data;
}

template<typename T>
Queue<T>::Queue() {
//    frist = new Node();
//    last = frist;
//    frist->prev = last;
//    last->next = frist;

    frist == nullptr;
    last == nullptr;
}

template<typename T>
Queue<T>::~Queue() {
    if(frist == nullptr){
        return;
    }
    Node* current = frist->next;
    while(current != frist){
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    delete frist;
}

template<typename T>
void Queue<T>::push(T data) {
//    Node* temp = frist;
//
//    frist = new Node();
//    frist->data = data;
//    frist->next = temp;
//    temp->prev = frist;
//
//    frist->prev = last;
//    last->next = frist;

    if(last == nullptr){
        frist = new Node();
        frist->data = data;
        last = frist;

        frist->next = last;
        frist->prev = last;
    }else{
//        Node* temp = new Node();
//        temp->data = data;
//
//        last->next = temp;
//        temp->next = frist;
//        frist->prev = temp;
//        last = temp;

        Node* temp = frist;

        frist = new Node();
        frist->data = data;
        frist->next = temp;
        frist->prev = last;
        temp->prev = frist;
        last->next = frist;
    }
}

template<typename T>
void Queue<T>::insert(T data, unsigned int idx) {
    if(frist == nullptr){
        throw QueueException("Index out of range");
    }

    if(frist->next == frist){
        frist->data = data;
    }

    Node* current = frist->next;
    for (int i = 1; i < idx & current != frist; ++i) {
        current = current->next;
    }
    if(current == frist){
        throw QueueException("Index out of range");
    }

    Node* temp = new Node();
    temp->data = data;

    temp->next = current;
    temp->prev = current->prev;

    current->prev->next = temp;
    current->prev = temp;

    frist->prev = last;
    last->next = frist;
}

template<typename T>
void Queue<T>::remove(unsigned int idx) {

    if(frist == nullptr){
        throw QueueException("Index out of range");
    }

    if(idx == 0){
        last->next = frist->next;
        frist->next->prev = last;
        delete frist;
        frist = last->next;
        return;
    }

    Node* current = frist->next;
    for (int i = 1; i < idx & current != frist; ++i) {
        current = current->next;
    }
    if(current == frist){
        throw QueueException("Index out of range");
    }

    Node* prev = current->prev;
    Node* next = current->next;

    prev->next = next;
    next->prev = prev;

    delete current;
}

template<typename T>
T Queue<T>::pop() {
    if(frist == nullptr){
        throw QueueException("Queue is empty");
    }
    T result = last->data;
    Node* temp = last;

    if(frist == last){
        frist = nullptr;
        last = nullptr;
        return result;
    }

    if(temp->prev == frist){
        frist->next = frist;
        frist->prev = frist;
        last = frist;
    }else {
        last = temp->prev;
        last->next = frist;
    }
    delete temp;



//    frist->prev = last;
//    last->next = frist;

    return result;
}