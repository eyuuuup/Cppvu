#include <iostream>
#include <vector>
using namespace std;

#ifndef MERGESORT_H
#define MERGESORT_H

bool copyArray = true;

template <typename T> void merge(const vector<T>& unsorted, int start, int mid, int end, vector<T>& sorted)  {

    int leftPointer = 0;
    int rightPointer = 0;
    int sortedPointer = start;
    int leftSize = mid - start + 1;
    int rightSize = end - mid;


    vector<T> left(leftSize); 
    vector<T> right(rightSize); 
  
    for (int i = 0; i < leftSize; i++) {
        left.at(i) = sorted.at(start + i); 
    }
            
    for (int j = 0; j < rightSize; j++) {
        right.at(j) = sorted.at(mid + 1 + j); 
    }

    while(leftPointer < leftSize && rightPointer < rightSize) {
        if(left.at(leftPointer) <= right.at(rightPointer)) {
            sorted.at(sortedPointer) = left.at(i);
            leftPointer++;
        } else {
            sorted.at(sortedPointer) = right.at(rightPointer);
            rightPointer++;
        }
         sortedPointer++;
    }

    while(leftPointer < leftSize) {
        sorted.at(sortedPointer) = left.at(leftPointer);
        sortedPointer++;
        leftPointer++;
    }
    
    while(rightPointer < rightSize) {
        sorted.at(sortedPointer) = right.at(rightPointer);
        rightPointer++;
        sortedPointer++;
    }
}

template <typename T> void mergeSort(const vector<T>& unsorted, int begin, int end, vector<T>& sorted) {

        if(begin < end) {
       
            if(copyArray) {
                sorted = unsorted;
                hit = false;
            }

            int mid = begin + (end-begin)/2;
                
            mergeSort(unsorted, begin, mid, sorted); 
            mergeSort(unsorted, mid + 1, end, sorted); 
            merge(unsorted, begin, mid, end, sorted); 
    }
    
} 

#endif