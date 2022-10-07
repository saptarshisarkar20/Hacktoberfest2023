class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set <vector<int>> s;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
        	int target = 0 - nums[i];
        	int l = i + 1;
        	int r = nums.size() - 1;
        	while(l < r){
        		int sum = nums[l] + nums[r];
        		if(sum == target){
        			s.insert(vector <int>{nums[i] , nums[l] , nums[r]});
        			l++;
        		}else if(sum > target){
        			r--;
        		}else{
        			l ++;
        		}
    	    }
        }
        vector<vector<int>> ans;
        for(auto it : s){
        	ans.push_back(it);
        }
        return ans;
    }
