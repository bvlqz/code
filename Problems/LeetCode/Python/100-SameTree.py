# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    isValid = True
    
    def checkTrees(self, nodeP, nodeQ):
        if nodeP != None:
            if nodeQ.left == None and nodeP.left != None: 
                self.isValid = False
            else:
                self.checkTrees(nodeP.left, nodeQ.left)
            
            if nodeP.val != nodeQ.val:
                self.isValid = False
            
            if nodeQ.right == None and nodeP.right != None:
                self.isValid = False
            else:
                self.checkTrees(nodeP.right, nodeQ.right)

    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p == None and q != None:
            return False
        
        if q == None and p != None:
            return False
        
        self.isValid = True
        self.checkTrees(p, q)
        self.checkTrees(q, p)
        return self.isValid
        
        
        
