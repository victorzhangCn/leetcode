/******************************************************************
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * 
 * Example:
 * 
 * Input: "babad"
 * 
 * Output: "bab"
 * 
 * Note: "aba" is also a valid answer.
 * Example:
 * 
 * Input: "cbbd"
 * 
 * Output: "bb"
 *****************************************************************/

#include <string>
#include <iostream>


using namespace std;

/****************************************************************/

class Solution {
public:
    string longestPalindrome(string s) {
        int res_start = 0;
        int res_end = 0;
        int max_len = 0;
        for (string::size_type start = 0; start != s.size(); ++start) {
            for (string::size_type end = start+1; end != s.size() + 1; ++end) {
                if (max_len > end-start) {
                    continue;
                }
                if (isPalindromic(s, start, end)) {
                    if (end - start > max_len) {
                        max_len = end-start;
                        res_start = start;
                        res_end = end;
                    }
                }
            }
        }

        return s.substr(res_start, res_end-res_start);
    }

    bool isPalindromic(const string& s, int start, int end) {
        while(start < end && s[start] == s[end-1]) {
            start++;
            end--;
        }
        return start >= end? true:false;
    }
};

/****************************************************************/

int main() {
    Solution s;
    cout << s.longestPalindrome(string(1000, '1')) <<endl;
    cout << s.longestPalindrome("cbbd") <<endl;
    cout << s.longestPalindrome("babad") <<endl;
}
