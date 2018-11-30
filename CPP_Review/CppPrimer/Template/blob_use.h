//
// Created by alex on 11/30/18.
//

#include "blob.h"
template<typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}

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