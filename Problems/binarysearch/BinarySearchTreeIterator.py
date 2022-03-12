# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
    orderedValues = set()

    def __init__(self, root):
        if root == None: 
            return
        
        values = []
        stack = [root]

        while len(stack) > 0:
            current = stack.pop(0)
            values.append(current.val)

            if current.left != None:
                stack.append(current.left)

            if current.right != None:
                stack.append(current.right)

        self.orderedValues = set(values)

    def next(self):
        return self.orderedValues.pop()

    def hasnext(self):
        return len(self.orderedValues) != 0
        
