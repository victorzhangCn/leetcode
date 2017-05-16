/*****************************************************************
 * 
 * Implement regular expression matching with support for '.' and '*'.
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 * 
 ****************************************************************/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

/****************************************************************/

class Solution {
public:
    bool isMatch(string s, string p) {
        map<int, vector<int>> res; 

        if (p == "" && s == "") {
            return true;
        }

        for (string::size_type p_index = 0; p_index < p.size(); ++p_index) {
            if(p[p_index] == '*') {
                continue;
            }

            if (p_index == 0) {
                res[0] = get_match_indexs(s, p, 0, 0);
            } else {
                auto last_p_index = p_index - 1;
                while (p[last_p_index] == '*') {
                    last_p_index--;
                }

                vector<int> s_indexs;
                for(auto s_index : res[last_p_index]) {
                    auto new_set = get_match_indexs(s, p, s_index, p_index);
                    vector<int> tmp(s_indexs.size() + new_set.size());
                    auto iter = set_union(s_indexs.begin(), s_indexs.end(), new_set.begin(), new_set.end(), tmp.begin());
                    tmp.resize(iter - tmp.begin()); 
                    s_indexs = vector<int>(tmp.begin(), tmp.end());
                }
                res[p_index] = s_indexs;
            }
        }
        
        auto last_p_index = p.size() - 1;
        while (p[last_p_index] == '*') {
            last_p_index -- ;
        }

        auto match_indexs = res[last_p_index];
        if(find(match_indexs.begin(), match_indexs.end(), s.size()) != match_indexs.end())
        {
            return true;
        } else {
            return false;
        }

    }

    vector<int> get_match_indexs(string s, string p, string::size_type s_last_index, string::size_type p_index) {
        bool star = false;
        if (p_index == p.size() -1) {
            star = false;
        } else { 
            star = p[p_index+1] == '*' ? true : false;
        }
        
        vector<int> res;
        if (star) {
            res.push_back(s_last_index);
            for (auto index = s_last_index; index < s.size(); ++index) {
                if (s[index] == p[p_index] || p[p_index] == '.') {
                    res.push_back(index+1);
                } else {
                    break;
                }
            }
        } else {
            if (s_last_index < s.size()) {
                if (s[s_last_index] == p[p_index] || p[p_index] == '.') {
                    res.push_back(s_last_index+1);
                }
            }
        }
        
        return res;
    }

};

/****************************************************************/


int main() {
/*
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 */
    Solution s;
    string s1;
    string s2;
    cout << s.isMatch("aaaaaaaaab", "a*a*a*a*a*a*a*b") <<endl;
    cout << s.isMatch(s1, s2) <<endl;
}
