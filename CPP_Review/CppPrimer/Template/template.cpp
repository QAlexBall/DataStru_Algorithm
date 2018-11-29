//
// Created by alex on 11/28/18.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <memory>

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

// 类模板
template <typename T> class Blob {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    Blob() = default;
    Blob(std::initializer_list<T> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data-> empty(); }
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    T& back();
    T& operator[] (size_type i);
private:
    std::shared_ptr<vector<T>> data;
    // 若data[i]无效,则抛出msg.
    void check(size_type i, const std::string &msg) const;

};


template<typename T>
Blob<T>::Blob(initializer_list<T> il) {

}

template<typename T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template<typename T>
T &Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template<typename T>
T &Blob<T>::operator[](Blob::size_type i) {
    // 如果i太大,check会抛出异常,阻止访问一个不存在的元素
    check(i, "subscript out of range");
    return (*data)[i];
}

template<typename T>
void Blob<T>::check(Blob::size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

void test() {
    cout << compare(1, 2) << endl;
    cout << compare("abc", "xyz") << endl; // "xyz" < "abc" ???
    cout << compare1("bcd", "abc") << endl; // int compare(const char (&p1)[3], const char (&p2)[3])
    cout << compare2("abc", "xyz") << endl;
}

//void test1() {
//    std::string s = "abc";
//    std::string t = "def";
//
//    const char u[] = "ghi";
//    const char v[] = "jkl";
//
//
//    std::cout << s << (s < t ? "<" : ">=") << t << std::endl;
//    std::cout << u << (std::strcmp(u, v) ? "<" : ">=") << v << std::endl;
//}


int main() {
    test();
    return 0;
}