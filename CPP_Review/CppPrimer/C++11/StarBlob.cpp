//
// Created by alex on 11/30/18.
//

#include "StarBlob.h"
using namespace std;

StrBlob::StrBlob() : data(make_shared<vector<string>>()){ }

StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) { }

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

std::string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::check(StrBlob::size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw out_of_range(msg);
}
