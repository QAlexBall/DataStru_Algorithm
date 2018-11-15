//
// Created by alex on 11/11/18.
//

#ifndef C_SORT_SORT_H
#define C_SORT_SORT_H

#include <iostream>

template <class T>
class Meta {
public:
    virtual void swap(T &a, T &b) {
        T temp = a;
        a = b;
        b = temp;
    }
};

template <class T>
class Sort : public Meta<T> {
private:
    T *array;
    int n{};
public:
    Sort() = default;
    explicit Sort(T *array, int n);
    ~Sort() = default;
//    void swap(T &a, T &b);  // 交换两个元素
    void swap(T &a, T &b) {
        Meta<T>::swap(a, b);
    }

    void InsertSort();
    void InsertSort1(); // 折半插入排序
    void ShellSort();
    void BubbleSort();
    int Partition(T *array, int low, int high); // 划分函数
    void QuickSort(T *array, int low, int high);
    void SelectSort();

    void BuildMaxHeap(T *array, int len);
    void AdjustDown(T *array, int k, int len);
    void HeapSort(T *array, int len);
    void BuildMinHeap(T *array, int len);
    void AdjustUp(T *array, int k);
    void HeapSortUp(T *array, int len);

    void Merge(T *array, int low, int mid, int high);
    void MergeSort(T *array, int low, int high);
    void output();
};
#endif //C_SORT_SORT_H
