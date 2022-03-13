# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    leafNodes = 0
    nonLeafNodes = 0

    def checkNodes(self, node):
        if node:
            if node.left != None or node.right != None:
                self.checkNodes(node.left)
                self.checkNodes(node.right)
                self.nonLeafNodes += 1

            if node.left == None and node.right == None:
                self.leafNodes += 1

    def solve(self, root):
        self.leafNodes = 0
        self.nonLeafNodes = 0
        self.checkNodes(root)
        return [self.leafNodes, self.nonLeafNodes]
