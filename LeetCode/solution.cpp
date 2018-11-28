#include <iostream>
using namespace std;

class Solution {
    void backtrack(string &s, int i, std::vector<string> &res) {
        if (i == s.size()) {
            res.push_back(s);
            return;
        }
        backtrack(s, i + 1, res);
        if (isalpha(s[i])) {
            // toggle case
            s[i] ^= (1 << 5);//大小写转换
            backtrack(s, i + 1, res);
        }
    }
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtrack(S, 0, res);
        return res;
    }
};

int main() {
    string a = "a1b2";
    Solution solution;
    std::vector<string> res = solution.letterCasePermutation(a);
    for (auto r : res) {
        cout << r << endl;
    }
    return 0;
}