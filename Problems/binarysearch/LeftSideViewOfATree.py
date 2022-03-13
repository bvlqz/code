# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right  

class Solution:
    nodes = {}

    def dfs(self, node, lvl):
        if node:
            self.dfs(node.right, lvl + 1) 
            self.dfs(node.left, lvl + 1)
            self.nodes[lvl] = node.val

    def solve(self, root):
        self.nodes = {}
        self.dfs(root, 0)
        
        result = []
        for level in range(len(self.nodes)):
            result.append(self.nodes[level])
        
        return result
