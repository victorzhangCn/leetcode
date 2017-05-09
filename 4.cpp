/***********************************************
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * 
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 */

#include <vector>
#include <iostream>

using namespace std;

/****************************************/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto total = nums1.size() + nums2.size();
        double res = 0;

        
        if (total % 2 == 0) {
            int count = total / 2 + 1;

            int value1 = 0;
            int value2 = 0;

            int index1 = 0;
            int index2 = 0;
            for (int i=0; i != count; ++i) {
                value1 = value2;
                value2 = nextValue(nums1, index1, nums2, index2);
            }

            return double(value1 + value2) / 2;

        } else {
            int count = (total + 1) / 2;
            int index1 = 0;
            int index2 = 0;
            for (int i=0; i != count; ++i) {
                res = nextValue(nums1, index1, nums2, index2);
            }
            return res;
        }
    }

    int nextValue(vector<int>& nums1, int& index1, vector<int>& nums2, int& index2) {
        int res = 0;
        if (index1 >= nums1.size()) {
            if (index2 >= nums2.size()) {
                abort();
            } else {
                res = nums2[index2];
                ++index2;
                return res;
            }
        } else if (index2 >= nums2.size()) {
            if (index1 >= nums1.size()) {
                abort();
            } else {
                res = nums1[index1];
                ++index1;
                return res;
            }
        }
        
        if (nums1[index1] < nums2[index2]) {
            res = nums1[index1];
            ++index1;
        } else {
            res = nums2[index2];
            ++index2;
        }
        return res;
    }
};

/***************************************/

int main() {
    Solution s;
    vector<int> num1{1};
    vector<int> num2{};
    cout << s.findMedianSortedArrays(num1, num2) << endl;
}
