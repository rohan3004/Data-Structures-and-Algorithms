#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

template <typename T>
class Node
{
    public:
    T data;
    Node* prev;
    Node* next;
    Node(T d):data(d),prev(nullptr),next(nullptr){}
};

template <typename T>
class List{
    Node<T>* head;
    Node<T>* tail;
    int size;
    Node<T>* merge(Node<T>* left, Node<T>* right)
    {
        Node<T>* dummy = new Node<T>(0);
        Node<T>* curr = dummy;

        while(left && right)
        {
            if(left->data < right->data)
            {
                curr->next = left;
                left->prev = curr;
                left = left->next;
            }
            else
            {
                curr->next = right;
                right->prev = curr;
                right = right->next;
            }
            curr= curr->next;
        }

        if(left){
            curr->next = left;
            left->prev = curr;
        }
        else if(right)
        {
            curr->next = right;
            right->prev = curr;
        }

        Node<T>* mergedHead = dummy->next;
        delete dummy;

        return mergedHead;
    }
    Node<T>* find_middle(Node<T>* head){
        Node<T>* slow = head;
        Node<T>* fast = head;

        while(fast && fast->next && fast->next->next)
        {
            slow=slow->next;
            fast =fast->next->next;
        }

        return slow;
    }
    Node<T>* merge_sort(Node<T>* head)
    {
        if(!head || !head->next)
            return head;

        Node<T>* mid = find_middle(head);
        Node<T>* left = head;
        Node<T>* right = mid->next;
        mid->next=nullptr;
        right->prev = nullptr;

        left = merge_sort(left);
        right = merge_sort(right);

        return merge(left, right);
    }
    public:
    List():head(nullptr),tail(nullptr),size(0){}
    void push_back(T data){
        Node<T>* newnode = new Node<T>(data);
        if(head==nullptr){
            size++;
            head=tail=newnode;
            return;
        }
        size++;
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
    }
    void push_front(T data){
        Node<T>* newnode = new Node<T>(data);
        if(head==nullptr){
            size++;
            head=tail=newnode;
            return;
        }
        size++;
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
    void pop_front()
    {
        if(head==nullptr)
        {
            cout<<"List is Empty\n";
            return;
        }
        size--;
        Node<T>* temp=head;
        head=head->next;
        head->prev=nullptr;
        delete temp;
    }
    void pop_back()
    {
        if(tail==nullptr)
        {
            cout<<"List is Empty\n";
            return;
        }
        size--;
        Node<T>* temp=tail;
        tail=tail->prev;
        tail->next=nullptr;
        delete temp;
    }
    void display()
    {
        Node<T>* curr=head;
        while(curr!=nullptr)
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
    void r_display()
    {
        Node<T>* curr=tail;
        while(curr!=nullptr)
        {
            cout<<curr->data<<" ";
            curr=curr->prev;
        }
        cout<<endl;
    }
    int get_size(){
        return size;
    }
    void sort()
    {
        head=merge_sort(head);
    }
    T front()
    {
        return head->data;
    }
    T back()
    {
        return tail->data;
    }
};
#endif