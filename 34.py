# Given an array of integers sorted in ascending order, find the begining and ending position of a given target value.
# 
# Your algorithm's runtime complexity must be in the order of O(log n).
# 
# If the target is not found in the array, return [-1, -1].
# 
# For example,
# Given [5, 7, 7, 8, 8, 10] and target value 8,
# return [3, 4].

class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) == 0 or target < nums[0] or target > nums[-1]:
            return [-1, -1]

        res = []

        start = 0
        end = len(nums)

        while start != end:
            mid = (start + end) / 2
            if nums[mid] >= target:
                end = mid
            else:
                start = mid + 1

        if nums[start] == target:
            res.append(start)
        else:
            return [-1, -1]

        start = 0
        end = len(nums)

        while start != end:
            mid = (start + end) / 2
            if nums[mid] > target:
                end = mid
            else:
                start = mid + 1

        if nums[end-1] == target:
            res.append(end-1)
        else:
            return [-1, -1]
        return res

if __name__ == "__main__":
    s = Solution()
    print s.searchRange([5, 7, 7, 8, 8, 10], 5)
