class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[0] = true;
        
        int n = nums.size();
        int i=0;
        while(i<n and !dp[n-1])
        {
            if(dp[i])
            {
                int step_length = nums[i];
                for(int j=0;j<=step_length and j+i<n; j++)
                dp[i+j] = true;
            }
            i++;
        }
        return dp[n-1];
    }
};
