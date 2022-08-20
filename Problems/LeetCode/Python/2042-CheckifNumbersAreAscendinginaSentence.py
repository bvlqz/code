class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        asList = s.split(" ")
        onlyNums = [int(value) for value in asList if value.isnumeric()]
        
        currentValue = 0
        for value in onlyNums:
            if value <= currentValue: return False
            currentValue = value
        
        return True
        
