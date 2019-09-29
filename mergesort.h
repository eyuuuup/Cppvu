#include <iostream>
#include <vector>
using namespace std;

#ifndef MERGESORT_H
#define MERGESORT_H

int hit = 0;

template <typename T> void merge(const vector<T>& unsorted, int start, int mid, int end, vector<T>& sorted)  {
    //cout <<"hit" << endl;
    int i = 0;
    int j = 0;
    int k = start;
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

    while(i < leftSize && j < rightSize) {
        if(left.at(i) <= right.at(j)) {
            sorted.at(k) = left.at(i);
            i++;
        } else {
            sorted.at(k) = right.at(j);
            j++;
        }
         k++;
    }

    while( i < leftSize) {
        sorted.at(k) = left.at(i);
        k++;
        i++;
    }
    while(j < rightSize) {
        sorted.at(k) = right.at(j);
        j++;
        k++;
    }



}

template <typename T> void mergeSort(const vector<T>& unsorted, int begin, int end, vector<T>& sorted) {

        if(begin < end) {
            if(hit == 0) {
                sorted = unsorted;
                hit++;
            }

            int mid = begin + (end-begin)/2;
            // cout << unsorted.size() << ":::";
            // cout << endl;
            // cout << mid << "Mid";
            // cout << endl;
                
            mergeSort(unsorted, begin, mid, sorted); 
            mergeSort(unsorted, mid + 1, end, sorted); 
            merge(unsorted, begin, mid, end, sorted); 
    }
    
} 



#endif