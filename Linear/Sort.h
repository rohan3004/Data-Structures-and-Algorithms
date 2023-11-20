/*Copyright© 2023 Rohan Chakaravarty
This header file contains all Sorting Algorithms:
    -> Bubble Sort
    -> Insertion Sort
    -> Selection Sort
    -> Quick Sort
    -> Merge Sort
    -> Heap Sort (It includes "Heap.h" header file for the heap sort)
    

This is opensource project and feel free contribute*/


#ifndef SORT_H
#define SORT_H

#include <vector>
#include "Heap.h"

//Bubble Sort
template <typename T>
void Bubble_Sort(std::vector<T>& arr)
{
    int n=arr.size();
    for (int i = 0; i < n-1; i++) {     
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

//Insertion Sort
template <typename T>
void Insertion_Sort(std::vector<T>& arr)
{
    int n=arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1]=key;
    }
}

//Selection Sort
template <typename T>
void Selection_Sort(std::vector<T>& arr)
{
    int n=arr.size();
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}


//Quick Sort
template <typename T>
int partition(std::vector<T>& arr,int si,int ei)
{
    int i=si-1;
    T pivot=arr[ei];
    for(int j=si;j<ei;j++)
    {
        if(arr[j]<=pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    i++;
    swap(arr[i],arr[ei]);
    return i;
}

template <typename T>
void Quick_Sort(std::vector<T>& arr, int si, int ei)
{
    if(si<ei)
    {
        int pi=partition<T>(arr,si,ei);
        Quick_Sort<T>(arr,si,pi-1);
        Quick_Sort<T>(arr,pi+1,ei);
    }
}

//Merge Sort
template <typename T>
void conquer(std::vector<T> &arr,int si,int mid,int ei)
{
    std::vector<T> merged(ei-si+1);
    int idx1=si,idx2=mid+1,x=0;
    while (idx1<=mid && idx2<=ei)
    {
        if(arr[idx1]<=arr[idx2])
            merged[x++]=arr[idx1++];
        else    
            merged[x++]=arr[idx2++];
    }

    while(idx1<=mid)
        merged[x++]=arr[idx1++];
    while (idx2<=ei)
        merged[x++]=arr[idx2++];

    for(int i=0,j=si;i<merged.size();i++,j++)
        arr[j]=merged[i];
}

template <typename T>
void Merge_Sort(std::vector<T> &arr, int si,int ei)
{
    if(si<=ei)
    {
        int mid=si+(ei-si)/2;
        Merge_Sort<T>(arr,si,mid);
        Merge_Sort<T>(arr,mid+1,ei);
        conquer<T>(arr,si,mid,ei);
    }
}

//Heap Sort
template <typename T>
void Heap_Sort(std::vector<T> &arr)
{
    int n=arr.size();
    build_heap<T>(arr);
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        Heapify<T>(arr,i,0);
    }
}

#endif