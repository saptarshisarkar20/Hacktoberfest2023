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