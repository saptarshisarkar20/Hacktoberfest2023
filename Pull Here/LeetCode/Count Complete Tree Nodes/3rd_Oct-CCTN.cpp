// Store the max depth and binary search [ min node count , max node count ] - check for node existence.
// Max depth takes O ( h ) and binary search takes O ( h * h ) time, O ( h ) space , h is log(n).

class Solution {
public:    
    int countNodes(TreeNode* root) {
        
        if (root == nullptr) {
            return 0;    
        }
        
        int maxLevel = 0;
        
        TreeNode* curr = root;
        
        while(curr != nullptr) {
            ++maxLevel;
            curr = curr->left;
        }
        
        int lo = 1 << (maxLevel-1);
        int hi = (1 << maxLevel) - 1;
        
        int mid, idx, res = lo;
        vector<int> path;
        
        while(lo <= hi) {     
            mid = lo + (hi - lo)/2;
            idx = mid;
            
            while(idx > 1) {
                path.push_back(idx);
                idx = idx/2;
            }
            
            curr = root;
            
            while(!path.empty()) {
                if(path.back() % 2 == 0) {
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
                
                path.pop_back();
            }
            
            if(curr == nullptr) {
                hi = mid-1;
            } else {
                res = mid;
                lo = mid+1;
            }
            
        }
        
        return res;
    }
};
