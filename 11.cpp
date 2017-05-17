/**************************************************
 * Given n non-negative integers a1, a2, ..., an, 
 * where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 **************************************************/

#include <vector>
#include <iostream>

using namespace std;

/***************************************************/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for (vector<int>::size_type i=0; i<height.size(); ++i) {
            
            if (height[i] == 0) {
                continue;
            }
            for (vector<int>::size_type j=i+(max/height[i]); j<height.size(); ++j) {
                int value = min(height[i], height[j]) * (j-i);
                max = max < value ? value : max;
            }
        }

        return max;
    }
};

/***************************************************/
int main(){
    Solution s;
    vector<int> v;
    for(int i=15000; i>=0; --i) {
        v.push_back(i);
    }
    cout << s.maxArea(v) << endl;
}
