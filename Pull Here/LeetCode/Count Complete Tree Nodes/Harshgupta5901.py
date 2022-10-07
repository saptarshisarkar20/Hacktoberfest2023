# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if(root is None):
            return 0
        count = 1
        if(root.right):
            count+=self.countNodes(root.right)
        if(root.left):
            count+=self.countNodes(root.left)
        return count
