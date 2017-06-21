/***************************************
 * 
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * 
 * For example, given n = 3, a solution set is:
 * 
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 * 
 **************************************/
#include <vector>
#include <string>
#include <iostream>

using namespace std; 

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return generateParenthesis(0, n);
    }

    vector<string> generateParenthesis(int left_not_paired, int left_to_print) {
        if (left_not_paired == 0 && left_to_print == 0){
            return {""};
        } else {
            vector<string> res;
            if (left_not_paired > 0) {
                auto tmp = generateParenthesis(left_not_paired-1, left_to_print);
                for (auto& s : tmp) {
                    res.push_back(")" + s);
                }
            }

            if (left_to_print > 0) {
                auto tmp = generateParenthesis(left_not_paired+1, left_to_print-1);
                for (auto& s : tmp) {
                    res.push_back("(" + s);
                }
            }
            return res;   
        }
    }
};

/*************************************/

int main() {
    Solution s;
    auto v = s.generateParenthesis(3);
    for (auto s : v) {
        cout << s << endl;
    }
}
