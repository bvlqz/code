class Solution:
    def solve(self, nums, k):
        top = 0
        bot = len(nums) - 1

        while (top != bot):
            
            elSum = nums[top] + nums[bot]

            if elSum == k:
                return True
            elif elSum > k:
                bot -= 1
            else:
                top += 1

        return False
