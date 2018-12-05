//
// Created by alex on 11/30/18.
//

#ifndef CPPPRIMER_BLOB_PTR_H
#define CPPPRIMER_BLOB_PTR_H
#include <iostream>
#include <memory>
#include <vector>
#include "blob.h"
template <typename T> class BlobPtr {
public:
    BlobPtr() : curr(0) { };
    explicit BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {
    }

    T& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    T& deref() const;
    BlobPtr& increment();
    BlobPtr& operator++();
    BlobPtr operator++(int);
    BlobPtr& operator--();
    BlobPtr operator--(int);
private:
    // 若检查成功,check返回一个指向vector的shared_ptr
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<T>> wptr;     // 保存一个weak_ptr,表示底层vector可能被销毁
    std::size_t curr;   // 数组中的当前位置
};

#endif //CPPPRIMER_BLOB_PTR_H
