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

    auto p = make_shared<int>(42);
    weak_ptr<int> wp(p);
    cout << wp.use_count() << endl;
    cout << wp.expired() << endl;
    cout << *wp.lock() << endl;

    auto p1 = make_shared<string>("abandon");
    weak_ptr<string> wp1(p1);
    cout << *wp1.lock() << endl;

    shared_ptr<vector<int>> p2 = make_shared<vector<int>>();
    *p2 = {1, 3, 5, 128, 64};
    cout << "*p2 = {1, 3, 5, 128, 64};" << endl;
    auto p3 = p2;
    const auto &p4 = p2;
    cout << "p2->back(): " << p2->back() << endl;
    weak_ptr<vector<int>> wp2(p2);
    cout << "wp2.use_count(): " << wp2.use_count() << endl;
    cout << "wp2.lock()->back(): " << wp2.lock()->back() << endl;

    Blob<int> s1 = {1, 9, 5, 8};
    Blob<int> s2 = s1;
    BlobPtr<int> blob_ptr(s1, 1);
    cout << "*blob_ptr.increment:" << *blob_ptr.increment() << endl;
}

int main() {
    test();
    return 0;
}