/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
* 
* You may assume that each input would have exactly one solution.
* 
* Example:
* Given nums = [2, 7, 11, 15], target = 9,
* 
* Because nums[0] + nums[1] = 2 + 7 = 9,
* return [0, 1].
**/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


/***********************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> num_to_index;
        for (vector<int>::size_type index = 0; index < nums.size(); ++index) {
            num_to_index[nums[index]] = index;
        }

        for (vector<int>::size_type index = 0; index < nums.size(); ++index) {
            auto iter = num_to_index.find(target-nums[index]);
            if (iter != num_to_index.end() && iter->second != static_cast<int>(index))
                return {static_cast<int>(index), iter->second};
        }

        return {};
    }

};

/***********************************************/

int main() {
    vector<int> nums{2, 7, 11, 15};
    Solution s;
    vector<int> test = s.twoSum(nums, 9);
    for (auto iter = test.begin(); iter != test.end(); ++iter) {
        cout << *iter <<endl;
    } 


    return 0;
}
