class Solution {
public:
    int visited[17];
    bool solve(vector<int> &nums,int k,int curr_sum,int target,int n,int start)
    {
        if(k==0)
            return 1;
        if(curr_sum>target)
            return 0;
        
         
        if(curr_sum==target)
        {
            return solve(nums,k-1,0,target,n,0);
        }
        for(int i=start;i<n;++i)
        {
            if(curr_sum+nums[i]>target)
                continue;
            if(visited[i]==0)
            {
                visited[i]=1;
                if(solve(nums,k,curr_sum+nums[i],target,n,i+1))
                    return 1;
                visited[i]=0; 
            }
        }
        return 0;
    }
//   comment er 14 gudsti 
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        memset(visited,0,sizeof(visited));
        for(auto x:nums)
            sum+=x;
        if(k==1)
            return 1;
        if(sum%k!=0 ||k>nums.size())
            return 0;
        return solve(nums,k,0,sum/k,nums.size(),0);
        
        
    }
};
