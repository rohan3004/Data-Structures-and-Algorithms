#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"
template <typename T>
class Queue{
    List<T>* a;
    public:
    Queue(){
        a = new List<T>();
    }
    void empty()
    {
        List<T>* t = a;
        delete t;
        a = new List<T>();
    }
    int size()
    {
        return a->get_size();
    }
    T front()
    {
        return a->front();
    }
    T back()
    {
        return a->back();
    }
    void push(T d)
    {
        a->push_back(d);
    }
    void pop()
    {
        a->pop_front();
    }
    void display()
    {
        cout<<"Elements in the Stack: ";
        a->display();
    }
    ~Queue()
    {
        delete a;
    }
};
#endif