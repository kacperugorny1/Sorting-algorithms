#pragma once
#include <random>
#include <iostream>

template<typename T>
int partition(T array[], int a, int b) {
    int l = a;
    int r = b - 1;
    while (l <= r) {
        if ((array[l] > array[b]) && (array[r] < array[b])) {
            std::swap(array[l], array[r]);
        }
        if (array[l] <= array[b])
            ++l;
        if (array[r] >= array[b])
            --r;
    }
    std::swap(array[l], array[b]);
    return l;
}

template<typename T>
void quickSort(T array[], int a, int b) {
    if (a >= b)
        return;
    int pivot = a + (b - a) / 2;
    std::swap(array[pivot], array[b]);
    pivot = partition(array, a, b);
    quickSort(array, a, pivot - 1);
    quickSort(array, pivot + 1, b);


}