class Solution {
public:
    
    vector<int> in;
    void traverse(TreeNode* node){
        if(!node) return;
        traverse(node -> left);
        in.emplace_back(node -> val);
        traverse(node -> right);
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        traverse(root);
        bool ok = true;
        for(int i = 1; i < in.size(); i++){
            if(in[i] <= in[i - 1])
                ok = false;
        }
        
        return ok;
    }
};