#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& A, int k) {
        int sum = 0;
        int n = A.size();
        for(int i=0;i<n;i++)
        sum += A[i];
        if (A.size() < k || sum % k) return false;
        
        vector<int> vis(A.size(), false);
        return solve(A, vis, sum / k, 0, 0, k);
    }
    
    bool solve(vector<int>& A,vector<int>& vis, int target, int curr_sum, int i, int k) {
        if (k == 0) 
            return true;
        
        if (curr_sum == target) 
            return solve(A, vis, target, 0, 0, k-1);
        
        for (int j = i; j < A.size(); j++) {
            if (vis[j] || curr_sum + A[j] > target) continue;
            
            vis[j] = true;
            if (solve(A, vis, target, curr_sum + A[j], j+1, k)) return true;
            vis[j] = false;
        }
        
        return false;
    }
};
int main() {
    int n;
    cin>>n;
    vector<int> A(n,0);
    for(int i=0;i<n;i++)
    cin>>A[i];
    int k;
    cin>>k;
    Solution obj;
    cout<<obj.canPartitionKSubsets(A,k);
}