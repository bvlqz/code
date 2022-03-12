class Solution:
    def solve(self, s):
        stack = []
        
        count = 0
        for bracket in s:
            if bracket == ")" and len(stack) == 0:
                count += 1

            elif bracket == "(":
                stack.append("(")
            elif bracket == ")" and stack[-1] == "(":
                stack.pop()
            
        count += len(stack)
        return count
