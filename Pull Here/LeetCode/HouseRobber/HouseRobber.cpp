int solve(vector<int>&nums,int i){
        //base case
        if(i>=nums.size()){
            return 0;
        }
        //exclude
        int p1=0+solve(nums,i+1);
        
        //include
        int p2=nums[i]+solve(nums,i+2);
        int maxi=max(p1,p2);
        return maxi;
    }
    int rob(vector<int>& nums) {
       
        int ans=solve(nums,0);
        return ans;
        
    }
