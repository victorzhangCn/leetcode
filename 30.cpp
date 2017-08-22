/*
 * You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
 * 
 * For example, given:
 * s: "barfoothefoobarman"
 * words: ["foo", "bar"]
 * 
 * You should return the indices: [0,9].
 * (order does not matter).
 */

#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int> word_count;
        for (const auto& word : words) {
            word_count[word] += 1;
        }
        vector<int> res;
        auto length = words[0].size();
        for (size_t index = 0; index < s.size()-length*(words.size())+1; ++index) {
            if (word_count.find(s.substr(index, length)) != word_count.end()) {
                auto tmp(word_count);
                bool satisfy = true;
                for (size_t i = 0; i<words.size(); ++i) {
                    auto word = s.substr(index + i*(length), length);
                    if(tmp.find(word) != tmp.end()) {
                        tmp[word] -- ; 
                        if (tmp[word] < 0) {
                            satisfy = false;
                            break;
                        }
                    } else {
                        satisfy = false;
                        break;
                    }
                }
                if (satisfy) {
                    res.push_back(index);
                }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<string> words{"a", "a", "b"};
    auto res = s.findSubstring("abababab", words);
    ostream_iterator<int> out(cout, " ");
    copy(res.begin(), res.end(), out);
    cout << endl;
    return 0; 
}
