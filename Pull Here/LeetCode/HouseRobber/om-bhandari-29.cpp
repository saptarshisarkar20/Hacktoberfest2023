class Solution {
public:
    int rob(vector<int>& nums) {
      int s1=0, s2 = 0;
      for(int i=0; i<nums.size(); i+=2)
      {
          s1 += nums[i];
          if((i+1) < nums.size()){
              s2 += nums[i + 1];
          }
      }
      return max(s1, s2);
};
