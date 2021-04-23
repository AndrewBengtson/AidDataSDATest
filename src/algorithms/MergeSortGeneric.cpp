//
// Created by agben on 4/22/2021.
//

#include "algorithms/MergeSortGeneric.h"
#include <utility>
#include <vector>
#include <iostream>


template <class Comparable>
MergeSortGeneric<Comparable>::MergeSortGeneric(vector<Comparable> inputArray) {
    //move avoids making a copy of the vector, which could be costly for large input arrays
    this->array = std::move(inputArray);
}
template <class Comparable>
vector<Comparable> MergeSortGeneric<Comparable>::sort(Comparator<Comparable>* comparator) {
    //we create the temporary array for merging
    vector<Comparable> temp = vector<Comparable>(this->array.size());
    //we call merge sort on the entire array
    mergeSort(temp, 0, array.size() - 1,comparator);
    //return temp, which contains the sorted array
    return temp;
}
template <class Comparable>
void MergeSortGeneric<Comparable>::mergeSort(vector<Comparable> &temp, int left, int right, Comparator<Comparable>* comparator) {
    //the breaking poComparable is when we get an array of size 1
    if(left<right) {
        //we define a center poComparable
        int center = (left + right) / 2;
        //merge the left to center
        mergeSort(temp, left, center,comparator);
        //merge the center to right
        mergeSort(temp, center + 1, right,comparator);
        //finally merge everything:
        //we define the endpoComparables of the left subarray
        int leftend = center;
        int numElements = right - left + 1;
        //we use an index to store where in the temporary array we have filled up to
        int tempIndex = left;
        //iterate the center
        center++;
        //next we iterate across the shorter of the two arrays
        while (left <= leftend && center <= right) {
            //we take the lesser of the two values in array and copy them over to temp
            if (comparator->lessThan(array[left] , array[center])) {
                temp[tempIndex] = array[left];
                left++;
            } else {
                temp[tempIndex] = array[center];
                center++;
            }
            //iterate indices
            tempIndex++;
        }
        //now that we have finished one array off we simply add remaining elements to the end of temp
        while (left <= leftend) {
            temp[tempIndex] = array[left];
            left++;
            tempIndex++;
        }
        while (center<=right) {
            temp[tempIndex] = array[center];
            center++;
            tempIndex++;
        }
        for(int i=0;i<numElements;++i,right--){
            array[right] = temp[right];
        }
    }
}
template class MergeSortGeneric<int>;