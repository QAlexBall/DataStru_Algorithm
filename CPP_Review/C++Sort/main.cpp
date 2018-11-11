#include <iostream>
#include "Sort/sort.h"
#include "Sort/sort.cpp"

void insert_sort() {
    int array[] = {18, 5, 3, 6, 4, 0};
    int n = sizeof(array) / sizeof(int);
    Sort<int> insert_sort(array, n);
    insert_sort.InsertSort();
    insert_sort.output();
}

void bubble_sort() {
    int array[] = {18, 5, 3, 6, 4, 0};
    int n = sizeof(array) / sizeof(int);
    Sort<int> bubble_sort(array, n);
    bubble_sort.BubbleSort();
    bubble_sort.output();
}

void quick_sort() {
     int array[] = {18, 5, 3, 6, 4, 0};
    int n = sizeof(array) / sizeof(int);
    Sort<int> quick_sort(array, n);
    quick_sort.QuickSort(array, 0, n - 1);
    quick_sort.output();
}
int main() {
    cout << "=============insert_sort==============" << endl;
    insert_sort();
    cout << "=============bubble_sort==============" << endl;
    bubble_sort();
    cout << "=============quick sort!==============" << endl;
    quick_sort();
    return 0;
}