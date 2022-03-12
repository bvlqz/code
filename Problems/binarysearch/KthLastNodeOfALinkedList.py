# class LLNode:
#     def __init__(self, val, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def solve(self, node, k):

        nodeToReturn = node
        currentNode = node

        for i in range(k):
            currentNode = currentNode.next
        
        while currentNode.next != None:
            currentNode = currentNode.next
            nodeToReturn = nodeToReturn.next

        return nodeToReturn.val
