/*
 *Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 *
 *For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *
 *Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 *
 */

#include <stack>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        vector<bool> valid(s.size(), false);
        stack<size_t> left_pos;
        for (size_t i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                left_pos.push(i);
            }
            if (s[i] == ')') {
                if (!left_pos.empty()) {
                    size_t left = left_pos.top();
                    left_pos.pop();
                    valid[i] = true;
                    valid[left] = true;
                }
            }
        }

        int max_length = 0;
        int length = 0;
        for (size_t i=0; i<valid.size(); ++i) {
            if (valid[i]) {
                ++ length;
            } else {
                max_length = max(max_length, length);
                length = 0;
            }
        }
        max_length = max(max_length, length);
        return max_length;
    }
};


int main() {
    cout << Solution().longestValidParentheses("()(()") << endl;
}
