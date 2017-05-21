/**********************************************
 * 
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
 * 
 * Find all unique quadruplets in the array which gives the sum of target.
 * 
 * Note: The solution set must not contain duplicate quadruplets.
 * 
 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 *   [-1,  0, 0, 1],
 *   [-2, -1, 1, 2],
 *   [-2,  0, 0, 2]
 * ]
 * 
 *********************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/********************************************/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return {};
        }
        sort(nums.begin(), nums.end());

        map<int, size_t> num_first_index;
        for (size_t index = 0; index < nums.size(); ++index) {
            if (num_first_index.find(nums[index]) == num_first_index.end()) {
                num_first_index[nums[index]] = index;
            }
        }

        vector<vector<int>> res;

        int value1 = nums[0] - 1;
        for (auto iter1 = nums.begin(); iter1 != nums.end() - 3; ++iter1) {
            if (*iter1 == value1) {
                continue;
            } else {
                value1 = *iter1;
            }

            if (*iter1 + *(nums.end()-3) + *(nums.end()-2) + *(nums.end()-1) < target) {
                continue;
            }
            int value2 = *iter1 - 1;
            for (auto iter2 = iter1+1; iter2 != nums.end() - 2; ++iter2) {
                if (*iter2 == value2) {
                    continue;
                } else {
                    value2 = *iter2;
                }

                if (*iter1 + *iter2 + *(nums.end()-2) + *(nums.end()-1) < target) {
                    continue;
                }
                
                int value3 = *iter2 - 1;
                for (auto iter3 = iter2+1; iter3 != nums.end() - 1; ++iter3) {
                    if (*iter3 == value3) {
                        continue;
                    } else {
                        value3 = *iter3;
                    }

                    if (*iter1 + *iter2 + *iter3 + *(nums.end()-1) < target) {
                        continue;
                    }

                    int expect = target - *iter1 - *iter2 - *iter3;
                    if (num_first_index.find(expect) != num_first_index.end()) {
                        auto index = num_first_index[expect];
                        if (nums.begin() + index > iter3) {
                            res.push_back({*iter1, *iter2, *iter3, expect});
                        } else {
                            if (*(iter3+1) == expect) {
                                res.push_back({*iter1, *iter2, *iter3, expect});
                            }
                        }
                    } 
                }
            }
        }
        return res;
    }
};

/********************************************/

int main(){
    Solution s;
    vector<int> nums{0,0,0,0};
    auto res = s.fourSum(nums, 0);
    for (auto& v : res) {
        for (auto num : v) {
            cout << num << " ";
        }
        cout << endl;
    }
}
