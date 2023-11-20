#ifndef STACK_H
#define STACK_H

#include "List.h"
template <typename T>
class Stack{
    List<T>* a;
    public:
    Stack(){
        a = new List<T>();
    }
    void push(T d)
    {
        a->push_back(d);
    }
    void pop()
    {
        a->pop_back();
    }
    T top()
    {
        return a->back();
    }
    int size()
    {
        return a->get_size();
    }
    void empty()
    {
        List<T>* t = a;
        delete t;
        a = new List<T>();
    }
    void display()
    {
        cout<<"Elements in the Queue: ";
        a->display();
    }
    ~Stack()
    {
        delete a;
    }
};
#endif