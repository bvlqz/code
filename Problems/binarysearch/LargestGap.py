class Solution:
    def solve(self, nums):
        nums.sort()
        largestGap = 0
        for i in range(1, len(nums)):
            currentGap = nums[i] - nums[i - 1]
            if  currentGap > largestGap:
                largestGap = currentGap
        
        return largestGap
