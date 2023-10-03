class Solution {
public:
    bool check(vector<int> nums,vector<bool>& visit,int currentsum,int index,int subset_sum,int t){
        if(t==0)return true;
        if(currentsum>subset_sum)return false;
        if(currentsum==subset_sum){
            return solve(nums,visit,0,0,subset_sum,t-1);
        }
        for(int x=index;x<nums.size();x++){
            if(visit[x])continue;
            visit[x] = true;
            if(solve(nums,visit,currentsum+nums[x],x+1,subset_sum,t))return true;
            visit[x] = false;
            if(currentsum==0)break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int t) {
        int n = nums.size();
        if(t > n)return false;
        int sum=0;
        for(auto n : nums)
            sum += n;
       if (nums.size() < t || sum % t) return false;
        int subset_sum = sum/t;
        vector<bool> v(n,false);
        sort(nums.begin(), nums.end(), greater<int>());
        if(nums[0]>subset_sum)
            return false;

        return check(nums,v,0,0,subset_sum,t);
    }
    
};