
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    values = []
    def dfs(self, node):
        if node:
            self.dfs(node.left)
            self.values.append(node.val)
            self.dfs(node.right)
    
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.values = []
        self.dfs(root)
        return self.values

      
