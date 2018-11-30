//
// Created by alex on 11/28/18.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <memory>
#include "blob_use.h"
#include "blob_ptr_use.h"
using namespace std;

// function template
template <typename T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

// 模板类型参数
template <typename T> T foo(T* p) {
    T tmp = *p;
    return tmp;
}

// 非类型模板参数
template <unsigned N, unsigned M>
int compare1(const char (&p1)[N], const char (&p2)[M]) {
    return strcmp(p1, p2);
}

// 编写类型无关代码
template <typename T> int compare2(const T & v1, const T &v2) {
    if (less<T>() (v1, v2)) return -1;
    if (less<T>() (v2, v1)) return  1;
    return 0;
}

void test() {
    cout << compare(1, 2) << endl;
    cout << compare("abc", "xyz") << endl; // "xyz" < "abc" ???
    cout << compare1("bcd", "abc") << endl; // int compare(const char (&p1)[3], const char (&p2)[3])
    cout << compare2("abc", "xyz") << endl;

    // 类模板成员函数的实例化
    /* 实例化Blob<int>和接受initializer_list<int>的构造函数 */
    Blob<int> squares = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    /* 实例化Blob<int>::size() const */
    for (size_t i = 0; i != squares.size(); ++i) {
        squares[i] = static_cast<int>(i * i);
        cout << squares[i] << endl;
    }
    cout << "hello" << endl;
    BlobPtr<int> blob_ptr(squares, 0);
    cout << "*blob ptr:" << *(++blob_ptr) << endl;
}

int main() {
    test();
    return 0;
}