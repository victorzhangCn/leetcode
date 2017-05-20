/************************************************************
 * 
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
 * Return the sum of the three integers. You may assume that each input would have exactly one solution.
 * 
 *     For example, given array S = {-1 2 1 -4}, and target = 1.
 * 
 *     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *     
 ***********************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <tuple>

using namespace std;

/***********************************************************/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) {
            return accumulate(nums.begin(), nums.end(), 0);
        }

        sort(nums.begin(), nums.end());

        map<int, tuple<int, int>> num_index_count;

        int res = nums[0] + nums[1] + nums[2];

        for (size_t index1 = 0; index1 < nums.size(); ++index1) {
            int num1 = nums[index1]; 
            for (size_t index2 = index1+1; index2 < nums.size(); ++index2) {
                int num2 = nums[index2];

                int expect = target - num1 - num2;
                if (expect < num2) {
                    continue;
                }

                auto iter = search(nums.begin(), nums.end(), expect);

                if (iter == nums.end()) {
                    iter--;
                }

                if (*iter == num2) {
                    iter = nums.begin() + index2 + 1;
                }

                if (*iter == expect) {
                    return target;
                }

                int new_res = num1 + num2 + *iter;
                if (abs(target - new_res) < abs(target - res)) {
                    res = new_res;
                }

                if (iter+1 != nums.end()) {
                    new_res = num1 + num2 + *(iter+1);
                    if (abs(target - new_res) < abs(target - res)) {
                        res = new_res;
                    }
                }
            }
        }
        
        return res;
    }

    vector<int>::iterator search(vector<int>::iterator begin, vector<int>::iterator end, int key) {
        if (end - begin <= 1) {
            return begin;
        }
        auto middle_iter = begin + (end-begin) / 2;
        if (*middle_iter == key) {
            return middle_iter;
        } else if(*middle_iter > key) {
            return search(begin, middle_iter, key);
        } else {
            return search(middle_iter+1, end, key);
        }
    }
};

/*********************************************************/

int main() {
    Solution s;
    vector<int> nums{-1, 0, 1, 1, 55};
    cout << s.threeSumClosest(nums, 3) << endl;
}
