//
// Created by Victor on 07.12.2020.
//

#ifndef LABS2_QUEUE_H
#define LABS2_QUEUE_H

#include <iostream>
#include "List.h"

template <typename T>
class Queue : List<T> {
private:
    class Node{
        friend Queue;
    public:
        T data = T();
        Node* next = nullptr;
        Node* prev = nullptr;
//        friend std::ostream &operator<<(std::ostream &stream, Queue<T>& queue);
    };

public:
    Node* frist = nullptr;
    Node* last = nullptr;

    T get(unsigned int idx) override;

    Queue();
    ~Queue();

    void push(T data) override;
    T pop() override;
    void insert(T data, unsigned int idx) override;
    void remove(unsigned int idx) override;

};

class QueueException : public std::exception {
public:
    explicit QueueException(const char* msg)
            : msg_(msg) {}

    ~QueueException() noexcept override = default;

    [[nodiscard]] const char* what() const noexcept override {
        return msg_;
    }

private:
    const char* msg_;
};

#include "Queue.inl"

#endif //LABS2_QUEUE_H
