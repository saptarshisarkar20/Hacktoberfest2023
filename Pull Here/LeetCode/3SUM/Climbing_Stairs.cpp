class Solution {
public:
    int f(int n, vector<int> &dp){
       
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            int left = dp[i-1];
            int right = dp[i-2];
            dp[i] = left+ right;
        }
        
        return dp[n-1];
    }
    
    
    int climbStairs(int n) {
       
        vector<int> dp(n+1, 0);
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            int left = dp[i-1];
            int right = dp[i-2];
            dp[i] = left+ right;
        }
        
        return dp[n];
    }
    
};
