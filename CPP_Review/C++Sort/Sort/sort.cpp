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

template<class T>
// 折半插入排序
void Sort<T>::InsertSort1() {


}

template<class T>
void Sort<T>::ShellSort() {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 对于每一组做一次插入排序
        for (int i = gap; i < n; i += 1) {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

//template <class T>
//void Sort<T>::swap(T &a, T &b) {
//    T temp = a;
//    a = b;
//    b = temp;
//}

template <class T>
void Sort<T>::BubbleSort() {
    for (int i = 0; i < n -1; i ++) {
        bool flag = false;              // 若没有发生交换说明排序完成
        for (int j = n - 1; j > i; j--) {
            if (array[j] < array[j - 1]) {
                swap(array[j], array[j - 1]);
                flag = true;
            }
        }
        if (!flag) {
            return;
        }
    }
}

template <class T>
int Sort<T>::Partition(T *array, int low, int high) {
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
        int pivot_pos = Partition(array, low, high);
        QuickSort(array, low, pivot_pos - 1);
        QuickSort(array, pivot_pos + 1, high);
    }
}

template<class T>
void Sort<T>::SelectSort() {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[min]) min = j;
        }
        if (min != i) swap(array[i], array[min]);
    }
}

template <class T>
void Sort<T>::BuildMinHeap(T *array, int len) {
    for (int i = len / 2; i > 0; i--)
        AdjustUp(array, i, len);
}

template <class T>
void Sort<T>::AdjustUp(T *array, int k) {
    T temp = array[k];
    int i = k / 2;
    while (i > 0 && array[i] < temp) {
        array[k] = array[i];
        k = i;
        i = k / 2;
    }
    array[k] = temp;
}

template <class T>
void Sort<T>::HeapSortUp(T *array, int len) {
    BuildMinHeap(array, len);
    for (int i = len; i > 1; i--) {
        swap(array[i], array[1]);
        AdjustDown(array, 1, i - 1);
    }
}

template <class T>
void Sort<T>::BuildMaxHeap(T *array, int len) {
    for (int i = len / 2; i > 0; i--)
        AdjustDown(array, i, len);
}

template<class T>
void Sort<T>::AdjustDown(T *array, int k, int len) {
    // 函数AdjustDown将元素k向下进行调整
    T temp = array[k];
    for (int i = 2 * k; i <= len; i *= 2) {
        if (i < len && array[i] < array[i + 1])
            i++;
        if (temp >= array[i]) break;
        else {
            array[k] = array[i];
            k = i;
        }
    }
    array[k] = temp;
}

template<class T>
void Sort<T>::HeapSort(T *array, int len) {
    BuildMaxHeap(array, len);
    for (int i = len; i > 1; i--) {
        swap(array[i], array[1]);
        AdjustDown(array, 1, i - 1);
    }
    int temp = array[0];
    for (int i = 0; i < len; i++) {
        if (array[i] > temp) {
            array[i - 1] = temp;
            break;
        }
        array[i] = array[i + 1];
    }
}

template<class T>
void Sort<T>::Merge(T *array, int low, int mid, int high) {
    this->array = array;
    T B[high];
    for (int k = low; k < high; k++) { // 将array中元素复制给B
        B[k] = array[k];
    }
    int i, j, k;
    for (i = low, j = mid + 1, k = i; i <= mid && j < high; k++) {
        if (B[i] <= B[j])
            array[k] = B[i++];
        else
            array[k] = B[j++];
    }
    while (i <= mid) array[k++] = B[i++];
    while (j < high) array[k++] = B[j++];
}

template<class T>
void Sort<T>::MergeSort(T *array, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(array, low, mid);
        MergeSort(array, mid + 1, high);
        Merge(array, low, mid, high);
    }
}

template <class T>
void Sort<T>::output() {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

