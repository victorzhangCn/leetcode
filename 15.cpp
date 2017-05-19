/*********************************************************
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * 
 * Note: The solution set must not contain duplicate triplets.
 * 
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 * 
 *********************************************************/

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

/*********************************************************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> num_count;

        for (auto num : nums) {
            if (num_count.find(num) == num_count.end()) {
                num_count[num] = 1; 
            } else {
                num_count[num] ++;
            }
        }

        vector<vector<int>> res;
        for (auto pair1 : num_count) {
            int num1 = pair1.first;
            int count1 = pair1.second;
            for (auto pair2 : num_count) {
                int num2 = pair2.first;
                int count2 = pair2.second;
                if (num2 < num1) {
                    continue;
                }

                if (num2 == num1 && count1 < 2) {
                    continue;
                }

                int num3 = -(num1 + num2);

                if (num_count.find(num3) == num_count.end()) {
                    continue;
                }

                if (num3 < num2) {
                    continue;
                }
                if (num3 == num2 && count2 < 2) {
                    continue;
                }

                if (num3 == num2 && num3 == num1 && count1 < 3) {
                    continue;
                }

                res.push_back({num1, num2, num3});
            }
        }
        return res;
    }
};

/*********************************************************/

int main() {
    Solution s;
    vector<int> v{-1, 0, 1, 2, -1, -4};
    auto res = s.threeSum(v);
    for (auto r : res) {
        cout << r[0] << "\t" << r[1] << "\t" << r[2] << endl;
    }
}
