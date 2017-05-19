/***************************************************
 * 
 * Write a function to find the longest common prefix string amongst an array of strings.
 * 
 *************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*************************************************/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        const string& base_s = strs[0];
        string::size_type index = 0;
        for(;;) {
            bool stop = false;
            if (base_s.size() == index) {
                break;
            }
            char c = base_s[index];
            for (auto& s : strs) {
                if (s.size() <= index) {
                    stop = true;
                    break;
                }
                if (s[index] != c) {
                    stop = true;
                    break;
                }
            }
            if (stop) {
                break;
            }
            index ++;
        }

        return base_s.substr(0, index);
    }
};

/*************************************************/

int main() {
    vector<string> strs{"abc", "a", "aaa"};
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;
}
