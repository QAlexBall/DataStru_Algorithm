//
// Created by alex on 11/11/18.
//

#ifndef C_SORT_SORT_H
#define C_SORT_SORT_H

#include <iostream>
using namespace std;

template <class T>
class Sort {
private:
    T *array;
    int n{};
public:
    Sort() = default;
    explicit Sort(T *array, int n);
    ~Sort() = default;
    void InsertSort();
    void BubbleSort();
    void QuickSort(T *array, int low, int high);
    void output();
};
#endif //C_SORT_SORT_H
