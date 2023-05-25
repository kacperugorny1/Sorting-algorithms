#pragma once
#include <random>
#include <iostream>

template<typename T>
int partition(T array[], int a, int b) {

    //int pivot = a + (b - a) / 2;
    //std::swap(array[pivot], array[b]);
    T pivot = array[a + (int)std::floor((b - a) / 2)];
    int l = a - 1; //a  
    int r = b + 1; //b-1
    
    while (1 == 1) {
        do
        {
            l = l + 1;
        } while (array[l] < pivot);

        do
        {
            r = r - 1;
        } while (array[r] > pivot);

        if (l >= r)
            return r;
        std::swap(array[l], array[r]);
    }
}

template<typename T>
void quickSort(T array[], int a, int b) {
    if (a >= b)
        return;
    int pivot = partition(array, a, b);
    quickSort(array, a, pivot);
    quickSort(array, pivot + 1, b);


}