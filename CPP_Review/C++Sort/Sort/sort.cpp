//
// Created by alex on 11/11/18.
//

#include "sort.h"

template <class T>
Sort<T>::Sort(T *array, int n) {
    this->array = array;
    this->n = n;
}

template <class T>
void Sort<T>::InsertSort() {
    for (int i = 1; i < n; i++) {
        int temp = array[i];
        int j = i;
        while(j >= 1 && array[j - 1] > temp) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = temp;
    }
}

template <class T>
void swap(T *a, T *b) {
    T temp = a;
    a = b;
    b = temp;
}
template <class T>
void Sort<T>::BubbleSort() {
    for (int i = 0; i < n -1; i ++) {
        bool flag = false;              // 若没有发生交换说明排序完成
        for (int j = n - 1; j > i; j--) {
            if (array[j] < array[j - 1]) {
                swap<T>(array[j], array[j - 1]);
                flag = true;
            }
        }
        if (!flag) {
            return;
        }
    }
}

template <class T>
int Partition(T *array, int low, int high) {
    T pivot = array[low];
    while (low < high) {
        while (low < high && array[high] >= pivot) --high;  // 如果右侧元素大于pivot则--high
        array[low] = array[high];                           // 将比pivot值小的元素移到其左侧
        while (low < high && array[low] <= pivot) ++low;    // 如果左侧元素小于pivot则++low
        array[high] = array[low];                           // 将比pivot值大的元素移到其右侧
    }
    array[low] = pivot;                                     // pivot存放到最终位置
    return low;                                             // 返回存放pivot的最终位置
}

template <class T>
void Sort<T>::QuickSort(T *array, int low, int high) {
    array = this->array;
    if (low < high) {
        // Partition()就是划分操作
        int pivot_pos = Partition<T>(array, low, high);
        QuickSort(array, low, pivot_pos - 1);
        QuickSort(array, pivot_pos + 1, high);
    }
}

template <class T>
void Sort<T>::output() {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
