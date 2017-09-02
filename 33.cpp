/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

/***************************************************/

class Solution {
public:
    vector<int>::iterator iter_search(vector<int>::iterator begin, vector<int>::iterator end, int target) {
        if (begin == end) {
            return begin;
        }
        if (*begin == target) {
            return begin;
        }
        if (*(end - 1) == target) { 
            return end-1;
        }

        auto mid = begin + (end - begin) / 2;

        if (*mid == target) {
            return mid;
        }

        if (*(end - 1) > *begin) {
            if (*mid < target) {
                return iter_search(mid + 1, end, target);
            } else {
                auto res = iter_search(begin, mid, target);
                if (res == mid) {
                    return end;
                } else {
                    return res;
                }
            }
        }

        if (*(end - 1) <= *begin && *begin <= *mid) {
            if (target < *(end - 1) || target > *mid) {
                return iter_search(mid+1, end, target);
            } else {
                auto res = iter_search(begin, mid, target);
                if (res == mid) {
                    res = end;
                }
                return res;
            }
        }

        if (*mid <= *(end - 1) && *(end - 1) <= *begin) {
            if (target > *begin || target < *mid) {
                auto res = iter_search(begin, mid, target);
                if (res == mid) {
                    res = end;
                }
                return res;
            } else {
                return iter_search(mid+1, end, target);
            }
        }
        assert(false);
        return end;
    }

    int search(vector<int>& nums, int target) {
        auto res = iter_search(nums.begin(), nums.end(), target);
        if (res == nums.end()) {
            return -1;
        } else 
            return res - nums.begin();
    }
};

/***************************************************/

int main() {
    vector<int> v{3, 1};
    cout << Solution().search(v, 2) << endl;
}
