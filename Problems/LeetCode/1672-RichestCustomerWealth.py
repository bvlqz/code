# https://leetcode.com/problems/richest-customer-wealth/

class Solution(object):
    def maximumWealth(self, accounts):

        maxWealth = 0
        
        for account in accounts:
            accountSum = 0
            
            for money in account:
                accountSum += money
            
            if accountSum > maxWealth:
                maxWealth = accountSum
            
        return maxWealth