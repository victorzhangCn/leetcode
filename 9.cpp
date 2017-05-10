/*****************************************************
 * 
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 ****************************************************/

#include <iostream>

using namespace std;

/***************************************************/

class Solution {
public:
    bool isPalindrome(int x) {
        int count = 0;
        int tmp_x = x;
        while (tmp_x > 0) {
            tmp_x /= 10;
            count ++;
        }

        int res = 0;
        for (int i=0; i<count; ++i) {
            int c = x / pow(10, i) % 10;
            res *= 10;
            res += c;
        }

        return res==x? true : false;
    }

    int pow(int base,int exponent) {
        int res=1;
        for (int i=0; i<exponent; ++i) {
            res *= base;
        }
        return res;
    }
};

/***************************************************/

int main() {
    Solution s;
    cout << s.isPalindrome(1) <<endl;
    cout << s.isPalindrome(111) <<endl;
    cout << s.isPalindrome(11) <<endl;
    cout << s.isPalindrome(121) <<endl;
    cout << s.isPalindrome(1221) <<endl;
    cout << s.isPalindrome(10) << endl;
}
