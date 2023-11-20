/*Copyright© 2023 Rohan Chakaravarty
This header file includes "List.h":
    -> First In First Out
    -> To empty the Queue
    -> Pushing element into the Queue from the back
    -> Poping element into the Queue from the front
    -> Displying the Queue
    -> To return size
    -> To return the front node and also the tail node
    

This is opensource project and feel free contribute*/


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