class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    if(nums[0] > 0){ //Since [0, 0, 0] is a possibility.
        return {};
    }
    
    for (int i=0; i<nums.size(); i++) {
        //Not considering duplicates in i, eg. [-1, -1, 0, 1], It will skip iteration of -1 at index 1 as it will tendto give us duplicate.
        if ((i>0) && (nums[i]==nums[i-1]))
            continue;
        //Two pointer to check for possible summation after i+1 index while grabbing the i index.
        int l = i+1, r = nums.size()-1;  
        while (l<r) {
            int s = nums[i]+nums[l]+nums[r];
            if (s>0) r--;  //When effective sum is greater then moving the right pointer to make it less
            else if (s<0) l++; //When effective sum is less then moving the right pointer to make it bigger
            else {
                res.push_back(vector<int> {nums[i], nums[l], nums[r]});
                while (l + 1 < s && nums[l]==nums[l+1]) l++; //Avoid duplicates of beg and end pointers.
                while (r - 1 > s && nums[r]==nums[r-1]) r--; 
                l++; r--;
            }
        }
    }
    return res;
}
};
