#include <utility>

//
// Created by alex on 12/5/18.
//

#ifndef CPPPRIMER_QUERY_RESULT_H
#define CPPPRIMER_QUERY_RESULT_H

#include <iosfwd>
#include "text_query.h"

class QueryResult {
    using line_no = std::vector<std::string>::size_type;
    friend std::ostream& print(std::ostream&, const QueryResult&);
 public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<std::vector<std::string>> f) :
                sought_(std::move(s)), lines_(std::move(p)), file_(std::move(f)) {}

 private:
    std::string sought_;
    std::shared_ptr<std::set<line_no>> lines_;
    std::shared_ptr<std::vector<std::string>> file_;
};
#endif //CPPPRIMER_QUERY_RESULT_H
