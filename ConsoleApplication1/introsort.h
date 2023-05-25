#pragma once
#include <algorithm>
#include <math.h>
#include "quicksort.h"



template<typename T>
void heapify(T arr[], int n, int i, int left_ind) {
    int largest = i + left_ind; 
    int l = left_ind + 2 * i + 1; 
    int r = left_ind + 2 * i + 2; 

    
    if (l < n + left_ind && arr[l] > arr[largest])
        largest = l;

    
    if (r < n + left_ind && arr[r] > arr[largest])
        largest = r;

   
    if (largest != i + left_ind) {
        std::swap(arr[i + left_ind], arr[largest]);
        heapify(arr, n, largest - left_ind, left_ind);
    }
}

template<typename T>
void heapSort(T arr[], int left_ind, int right_ind) {

    int n = right_ind - left_ind + 1;
    //utwórz kopiec
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i, left_ind);

    //usuñ najwiêkszy, utwórz kopiec
    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[left_ind], arr[left_ind + i]);

        heapify(arr, i, 0, left_ind);
    }
}

template<typename T>
void insertionSort(T arr[], int left_ind, int right_ind) {
    int j, i = left_ind + 1;
    while (i < right_ind + 1) {
        j = i;
        while (j > left_ind && arr[j - 1] > arr[j]) {
            std::swap(arr[j], arr[j - 1]);
            --j;
        }
        ++i;
    }
}

template<typename T>
void introsort_step(T array[], int left_ind, int right_ind, int maxdepth) {
    int len = right_ind - left_ind + 1;
    if (left_ind >= right_ind)
        return;
    if (len <= 16) {
        insertionSort(array, left_ind, right_ind);

    }
    else if (maxdepth == 0) {
        heapSort(array, left_ind, right_ind);

    }
    else {
        int pivot = partition(array, left_ind, right_ind);
        introsort_step(array, left_ind, pivot, maxdepth - 1);
        introsort_step(array, pivot + 1, right_ind, maxdepth - 1);

    }


}
template<typename T>
void introSort(T array[], int left_ind, int right_ind) {
    int max_depth = 2 * ((int)log2(right_ind - left_ind + 1));
    introsort_step(array, left_ind, right_ind, max_depth);
}

