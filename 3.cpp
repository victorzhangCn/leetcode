/**
 * 
 * Given a string, find the length of the longest substring without repeating characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
#include <assert.h>

#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

/**************************************************************/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, string::size_type> last_index;
        string::size_type res = 0;
        string::size_type start = 0;

        for (string::size_type i = 0; i != s.length(); ++i) {
            char c = s[i];
            if (last_index.find(c) != last_index.end()) {
                if (start <= last_index[c]) {
                    start = last_index[c] + 1;
                }
            }
            last_index[c] = i;
            auto new_res = i - start + 1;
            res = res > new_res ? res:new_res;
        }
        
        return static_cast<int>(res);
    }
};

/**************************************************************/

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("ppp") << endl;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
}
