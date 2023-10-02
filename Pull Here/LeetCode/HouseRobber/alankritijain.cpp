class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n);
        arr[0]=nums[0];
        for(int i=1;i<n;++i){
            int take=nums[i];
            if(i>1)
                take+=arr[i-2];
            int notake=arr[i-1];
            arr[i]=max(take,notake);
        }
        return arr[n-1];
    }
};
