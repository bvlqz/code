# class LLNode:
#     def __init__(self, val, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def solve(self, node):
        
        if node == None: return 0

        currNode = node
        count = 0

        while currNode.next != None:
            currNode = currNode.next
            count += 1

        return count + 1
