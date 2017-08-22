/*
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place, do not allocate extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 3 1 4 2 5
        // 3 1 4 5 2
        // 3 2 1 4 5 
        // 3 2 1 5 4
        // 3 2 4 1 5
        // 3 2 4 5 1
        // 3 2 5 4 1
        // 3 4 1 2 5
        // ...
        // 4 5 3 2 1
        // 4 1 2 3 4
        // ...
        // 5 4 3 2 1 6
        // 5 4 3 2 6 1 
        // 3 5 6 4 2 1
        // 3 6 1 2 4 5
        // 
        // 
        // 
        auto iter = nums.end() - 1;
        for (; iter != nums.begin(); --iter) {
            if (*(iter-1) < *iter){
                break;
            }
        }
        cout << *iter << endl;
        if (iter != nums.begin()) {
            auto min_iter = nums.end() - 1;
            for (; *min_iter <= *(iter-1) && min_iter != iter; --min_iter) {}
            swap(*min_iter, *(iter-1));
        }
        reverse(iter, nums.end());
    }
};


int main() {
    vector<int> v{3, 2, 1};
    Solution().nextPermutation(v);
    ostream_iterator<int> out_iter(cout, " ");
    copy(v.begin(), v.end(), out_iter);
    cout << endl;
}

