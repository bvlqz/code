class Solution:
    def solve(self, n):
        
        result = []

        for i in range(1, n + 1):
            strToAppend = ""
            if i % 3 == 0: strToAppend += "Fizz"
            if i % 5 == 0: strToAppend += "Buzz"

            if i % 3 != 0 and i % 5 != 0:
                result.append(str(i))
            else:
                result.append(strToAppend)

        return result
