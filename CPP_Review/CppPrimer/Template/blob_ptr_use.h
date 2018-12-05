//
// Created by alex on 11/30/18.
//

#include "blob_ptr.h"


template<typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string & msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound BlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
    --curr;
    check(curr, "decrement past begin of BlobPtr");
    return *this;
}

template<typename T>
T& BlobPtr<T>::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::increment() {
    check(curr, "increment past end of BlobPtr");
    ++curr; // 推进当前位置
    return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
    BlobPtr ret = *this;
    ++*this;
    return ret;
}



