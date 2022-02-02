# https://leetcode.com/problems/plus-one/

class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        
        # digits[-1] += 1
        
        asStr = ""
        for digit in digits:
            asStr += str(digit)
        
        result = str(int(asStr) + 1)
        
        return [int(digit) for digit in result]
        
        
        