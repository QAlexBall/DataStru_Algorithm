//
// Created by alex on 11/28/18.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void backtrack(string &s, int i, vector<string> &res) {
        if (i == s.size()) {
            res.push_back(s);
            return;
        }
        backtrack(s, i + 1, res);       // 不转换i位置字母
        if (isalpha(s[i])) {
            // toggle case
            s[i] ^= (1 << 5);   //大小写转换     if s[i] = A; 0110 0001 = 0100 0001 ^ 10 0000
                                //              if s[i] = a; 0100 0001 = 0110 0001 ^ 10 0000
            backtrack(s, i + 1, res);   // 考虑转换i位置字母,i位置之后的可能出现的情况
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
    vector<string> res = solution.letterCasePermutation(a);
    for (auto &r : res) {
        cout << r << endl;
    }
    cout << (1 << 5) << endl;
    char s = 97 ^ 32;
    cout << static_cast<int>(s) << endl;

    return 0;
}