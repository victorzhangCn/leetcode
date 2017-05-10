/**************************************
 * 
 * Reverse digits of an integer.
 * 
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 * 
 *************************************/

#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

/*************************************/

class Solution {
public:
    int reverse(int x) {
        string s = x > 0? to_string(x):to_string(-x);
        std::reverse(s.begin(), s.end());
        //return x>0? std::stoi(s): -std::stoi(s);
        int res = 0;
        for (auto c : s) {
            res *= 10;
            if (res%10 != 0) {
                return 0;
            }
            res += c-'0';
        }
        return x>0? res:-res;
    }
};

/*************************************/

int main() {
    Solution s;
    cout << s.reverse(123) << endl;
    cout << s.reverse(0) <<endl;
    cout << s.reverse(1534236469) <<endl;
}
