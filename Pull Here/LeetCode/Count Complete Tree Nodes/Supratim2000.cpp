class Solution {
public:
    int leftHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        int count=0;
        TreeNode* p=root;
        while(p)
        {
            count++;
            p=p->left;
        }
        return count;
    }
    
    int rightHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        int count=0;
        TreeNode* p=root;
        while(p)
        {
            count++;
            p=p->right;
        }
        return count;
    }
    
    int helper(TreeNode* root)
    {
        if(!root)
            return 0;
        int lh=leftHeight(root);
        int rh=rightHeight(root);
        return lh==rh?(1<<lh)-1:1+helper(root->left)+helper(root->right);
    }
    
    int countNodes(TreeNode* root) {
        return helper(root);
    }
};