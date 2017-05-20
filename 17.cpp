/***********************************************
 * Given a digit string, return all possible letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * 
 * 
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 ***********************************************/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }

        string table[10] = {
            " ", "","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> res{""};
        for (auto num : digits) {
            string& num_str = table[num - '0'];

            vector<string> new_res;
            for (auto c : num_str) {
                vector<string> tmp; 
                for(string r : res) {
                    tmp.push_back(r+c);
                }
                new_res.insert(new_res.end(), tmp.begin(), tmp.end());
            }

            swap(res, new_res);
        }

        return res;
    }
};

/***********************************************/

int main() {
    Solution s;
    auto res = s.letterCombinations("23");
    for (auto& s : res) {
        cout << s << endl;
    }
}
