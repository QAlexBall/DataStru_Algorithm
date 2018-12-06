//
// Created by alex on 12/6/18.
//

#include <iostream>
#include "query_result.h"

std::string make_plural(size_t ctr, const std::string &word,
                                    const std::string &ending) {
    return (ctr > 1) ? word + ending : word;
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
    // 如果找到了单词,打印出出现次数和所有出现的位置
    os << qr.sought_ << " occurs " << qr.lines_->size() << " "
       << make_plural(qr.lines_->size(), "time", "s") << std::endl;
    return os;
}
