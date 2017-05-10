/***************************************
 * Implement atoi to convert a string to an integer.
 * 
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 * 
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 **************************************/

#include <iostream>
#include <cmath>

using namespace std;

/**************************************/

class Solution {
public:
    int myAtoi(string str) {
        if(str.size() == 0) {
            return 0;
        }
        bool neg = false;
        bool started = false;
        long long res = 0;
        for (auto c : str) {
            if (!started) {
                if (c == '+' || c == '-' || (c >= '0' && c <= '9')) {
                    started = true;
                    if (c=='-') {
                        neg = true;
                    }

                    if (c>='0' && c <= '9') {
                         res = c-'0';
                    }
                } else if (c == ' ') {
                    continue;
                } else {
                    return 0;
                }
            } else {
                if (c>='0' && c <= '9') {
                    res *= 10;
                    res += c-'0';
                    if (res >= INT_MAX) {
                        break;
                    }
                } else {
                    break;
                }
            }
        }

        res = neg?-res:res;

        if (res >= INT_MAX){
            return INT_MAX;
        }
        if (res <= INT_MIN){
            return INT_MIN;
        }
        return res;
    }
};

/**************************************/

int main() {
    Solution s;
    cout << s.myAtoi("12345") <<endl;
    cout << s.myAtoi("-12345") <<endl;
    cout << s.myAtoi("   -12345a123") <<endl;
    cout << s.myAtoi("12312321321321312321321123")<<endl;
    cout << s.myAtoi("b123")<<endl;
    cout << s.myAtoi("+-123")<<endl;
    cout << s.myAtoi("-2147483648")<<endl;
    cout << s.myAtoi("-2147483647")<<endl;
}
