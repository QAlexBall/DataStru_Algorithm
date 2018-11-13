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
void shell_sort() {
    int array[] = {19, 5, 3, 6, 4, 0};
    int n = sizeof(array) / sizeof(int);
    Sort<int> shell_sort(array, n);
    shell_sort.ShellSort();
    shell_sort.output();
}
void bubble_sort() {
    int array[] = {20, 5, 3, 6, 4, 0};
    int n = sizeof(array) / sizeof(int);
    Sort<int> bubble_sort(array, n);
    bubble_sort.BubbleSort();
    bubble_sort.output();
}

void quick_sort() {
    int array[] = {21, 5, 3, 6, 4, 0};
    int n = sizeof(array) / sizeof(int);
    Sort<int> quick_sort(array, n);
    quick_sort.QuickSort(array, 0, n - 1);
    quick_sort.output();
}

void select_sort() {
    int array[] = {22, 5, 3, 6, 4, 0};
    int n = sizeof(array) / sizeof(int);
    Sort<int> select_sort(array, n);
    select_sort.SelectSort();
    select_sort.output();
}

void heap_sort() {
    int array[] = {28, 5, 3, 6, 4, 0, 1, 2, 89 , 100};
    int n = sizeof(array) / sizeof(int);
    Sort<int> heap_sort(array, n);
    heap_sort.HeapSort(array, n - 1);
    heap_sort.output();
}

void heap_sort_up() {
    int array[] = {18, 5, 3, 6, 4, 0, 1, 2, 89, 100};
    int n = sizeof(array) / sizeof(int);
    Sort<int> heap_sort_up(array, n);
    heap_sort_up.HeapSortUp(array, n - 1);
    heap_sort_up.output();
}

void merge_sort() {
    int array[] = {1, 5, 8, 10, 7, 9, 89};
    int n = sizeof(array) / sizeof(int);
    Sort<int> merge_sort(array, n);
    merge_sort.MergeSort(array, 0, n);
    merge_sort.output();
}
int main() {
    cout << "=============insert_sort!==============" << endl;
    insert_sort();
    cout << "=============shell_sort!===============" << endl;
    shell_sort();
    cout << "=============bubble_sort!==============" << endl;
    bubble_sort();
    cout << "=============quick sort!===============" << endl;
    quick_sort();
    cout << "=============select sort!==============" << endl;
    select_sort();
    cout << "=============heap sort!================" << endl;
    heap_sort();
    cout << "=============heap sort up!=============" << endl;
    heap_sort_up();
    cout << "=============merge sort!===============" << endl;
    merge_sort();
    return 0;
}