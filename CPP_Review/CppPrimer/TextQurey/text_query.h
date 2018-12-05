//
// Created by alex on 12/5/18.
//

#ifndef CPPPRIMER_TEXT_QUERY_H
#define CPPPRIMER_TEXT_QUERY_H

#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>
#include "query_result.h"
class TextQuery {
 public:
    using line_no = std::vector<std::string>::size_type;

    explicit TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;

 private:
    // 输入文件
    std::shared_ptr<std::vector<std::string>> file_;
    // 每个单词找到它所在的行号的集合的映射
    std::map<std::string,
            std::shared_ptr<std::set<line_no>>> wm_;
};

#endif //CPPPRIMER_TEXT_QUERY_H
