#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>

template<typename T>
void merge(T array[], int left_ind, int middle, int right_ind) {
    int left_size = middle - left_ind + 1;
    int right_size = right_ind - middle;
    T* left_arr = new T[left_size];
    T* right_arr = new T[right_size];

    int left_arr_ind = 0;
    int right_arr_ind = 0;
    
    //kopiowanie array do left_arr i right_arr
    for (int i = 0; i < left_size; ++i) 
        left_arr[i] = array[i + left_ind];
    for (int i = 0; i < right_size; ++i)
        right_arr[i] = array[middle + i + 1];
    
    
    while (left_arr_ind < left_size && right_arr_ind < right_size) 
        if (left_arr[left_arr_ind] <= right_arr[right_arr_ind])
            array[left_ind++] = left_arr[left_arr_ind++];
        else
            array[left_ind++] = right_arr[right_arr_ind++];
    while (left_arr_ind < left_size)
        array[left_ind++] = left_arr[left_arr_ind++];
    while (right_arr_ind < right_size)
        array[left_ind++] = right_arr[right_arr_ind++];


    delete[] left_arr;
    delete[] right_arr;

}
template<typename T>
void mergeSort(T array[], int left_ind, int right_ind) {
    if (right_ind <= left_ind)
        return;
    int middle = left_ind + (right_ind - left_ind) / 2;
    mergeSort(array, left_ind, middle);
    mergeSort(array, middle + 1, right_ind);
    merge(array, left_ind, middle, right_ind);

}
