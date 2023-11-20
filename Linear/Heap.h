/*Copyright© 2023 Rohan Chakaravarty
This header file contains Heap using vector:
    -> One by one elemnet insertion in heap O(n)
    -> Heapify method 
    -> Deletion in Heap
    -> Building Maximum Heap
    -> Displaying yhe Heap
    
This header file can be further inherited in "Sort.h"

This is opensource project and feel free contribute*/


#ifndef HEAP_H
#define HEAP_H

#include <vector>

//Heapify Method
template <typename T>
void Heapify(std::vector<T> &arr,int n,int i)
{
    int m=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && arr[l]>arr[m])
        m=l;

    if(r<n&& arr[r]>arr[m])
        m=r;

    if(m!=i)
    {
        swap(arr[m],arr[i]);
        Heapify<T>(arr,n,m);
    }
}

//building max heap
template <typename T>
void build_heap(std::vector<T> &arr)
{
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--)
        Heapify<T>(arr,n,i);
}

//displaying the heap
template <typename T>
void display(std::vector<T> &arr)
{
    for(auto i:arr)
        cout<<i<<" ";
    cout<<endl;
}

template <typename T>
void del_heap(std::vector<T> &arr)
{
    int n=arr.size();
    arr[0]=arr[n-1];
    arr.resize(n-1);
    Heapify<T>(arr,n,0);
}

//Return Parent of the Node
int parent(int i)
{
    return (i-1)/2;
}

//make heap
template <typename T>
void make_heap(std::vector<T> &arr, T data)
{
    int n=arr.size();
    n++;
    arr.resize(n);
    int i=n-1;
    arr[i]=data;

    while(i>0 && arr[i] > arr[parent(i)]){
        swap(arr[i],arr[parent(i)]);
        i=parent(i);
    }
}
#endif