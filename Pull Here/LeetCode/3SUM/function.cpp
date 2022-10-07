class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int t=-nums[i];
            int low=i+1,high=nums.size()-1;
            while(low<high){
                int sum=nums[low]+nums[high];
                if(sum<t)
                    low++;
                else if(sum>t)
                    high--;
                else{
                    vector<int> temp{nums[i],nums[low],nums[high]};
                    v.push_back(temp);
                    while(low<high && nums[low]==temp[1])
                        low++;
                    while(low<high && nums[high]==temp[2])
                        high--;
                }
            }
            while(i+1<nums.size() && nums[i+1]==nums[i])
                i++;
        }
        return v;
    }
};