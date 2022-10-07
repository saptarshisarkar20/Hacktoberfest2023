class Solution {
public:
    void findSubsetSum(vector<int>& nums,int n,int sum,vector<int> &dp){
        for(int i=0;i<(1<<n);i++){
            int temp = 0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    temp += nums[n-1-j];
                }
            }
            if(temp == sum){
                dp.push_back(i);
            }
        }
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto i : nums){
            sum += i;
        }
        if(sum % k != 0 || sum < k)
            return false;
        vector<int> dp;
        findSubsetSum(nums,nums.size(),sum/k,dp);
        if(dp.size() < k)
            return false;
        int ans = 0;
        for(int i=0;i<dp.size();i++){
            int temp = 0;
            for(int j=0;j<dp.size();j++){
                if(i!=j){
                    if((dp[i]|dp[j]) == (dp[i]^dp[j])){
                        temp++;
                    }
                }
            }
            if(temp>=k-1){
                ans++;
            }
        }
        return (ans >= k);
    }
};
