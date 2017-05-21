/*********************************************
 * 
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 * 
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 * 
 ********************************************/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*******************************************/

class Solution {
public:
    bool isValid(string s) {
        stack<char> my_stack;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                my_stack.push(c);
            } else {
                if (my_stack.empty()) {
                    return false;
                }
                auto top = my_stack.top();
                if (c == ')' && top != '(') {
                    return false;
                }
                if (c == ']' && top != '[') {
                    return false;
                }
                if (c == '}' && top != '{') {
                    return false;
                }
                my_stack.pop();
            }
        }
        return my_stack.empty() ? true :false;
    }
};

/******************************************/

int main() {
    Solution s;
    cout << s.isValid("()(){}[]") <<endl;
}
