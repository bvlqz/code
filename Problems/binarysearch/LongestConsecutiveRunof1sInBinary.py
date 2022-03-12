class Solution:
    def solve(self, n):
        nums = list(format(n, "b"))
        maxCount = 0; 
        count = 0;
        for element in nums:
            if element == "1":
                count += 1
                if count > maxCount:
                    maxCount = count
            else:
                count = 0
        return maxCount
