//
// Created by alex on 11/30/18.
//

#include "blob_ptr.h"


template<typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string & msg) const {
    return wptr.lock();
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
    BlobPtr &ret = *this;
    ++*this;
    return ret;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
    BlobPtr &ret = *this;
    --*this;
    return ret;
}


