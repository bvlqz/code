# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    rootVal = 0
    isValid = True

    def checkNodes(self, node):
        if node:
            if node.val != self.rootVal:
                self.isValid =False

            if node.left != None or node.right != None:
                self.checkNodes(node.left)
                self.checkNodes(node.right)

    def solve(self, root):
        self.rootVal = root.val
        self.checkNodes(root)

        return self.isValid
