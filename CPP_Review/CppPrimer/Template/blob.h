//
// Created by alex on 11/30/18.
//

#ifndef CPPPRIMER_BLOB_H
#define CPPPRIMER_BLOB_H
#include <vector>
#include <memory>
template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T>
    bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob {
    friend class BlobPtr<T>;
    friend bool operator==<T>
            (const Blob<T>&, const Blob<T>&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(std::initializer_list<T> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data-> empty(); }
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    T& back();
    T& operator[] (size_type i);
private:
    std::shared_ptr<std::vector<T>> data;
    // 若data[i]无效,则抛出msg.
    void check(size_type i, const std::string &msg) const;
};
#endif //CPPPRIMER_BLOB_H
