//
// Created by alex on 12/5/18.
//
#include <fstream>
#include <sstream>
#include "text_query.h"
#include "query_result.h"
using namespace std;

TextQuery::TextQuery(ifstream &is) : file_(new vector<string>) {
    string text;
    while (getline(is, text)) {
        file_->push_back(text);
        int n = static_cast<int>(file_->size() - 1);
        istringstream line(text);
        string word;
        while (line >> word) {
            auto &lines = wm_[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(static_cast<unsigned long &&>(n));
        }
    }
}

QueryResult TextQuery::query(const std::string &sought) const {
    static shared_ptr<set<line_no>> no_data(new set<line_no>);
    auto loc = wm_.find(sought);
    if (loc == wm_.end())
        return QueryResult(sought, no_data, file_);
    else
        return QueryResult(sought, loc->second, file_);
}
