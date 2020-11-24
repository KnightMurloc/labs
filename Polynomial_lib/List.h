//
// Created by Victor on 24.11.2020.
//

#ifndef LABS2_LIST_H
#define LABS2_LIST_H

template <typename T>
class List {
public:
    virtual void push(T* p) = 0;
    virtual T* pop() = 0;
    virtual void remove(unsigned int idx) = 0;
    virtual void insert(T* p, unsigned int idx) = 0;
    virtual T* get(unsigned int idx) = 0;
};


#endif //LABS2_LIST_H
