#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> maxMoneyAtHouse(n, 0);

        maxMoneyAtHouse[0] = nums[0];
        maxMoneyAtHouse[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            maxMoneyAtHouse[i] = max(maxMoneyAtHouse[i-1], maxMoneyAtHouse[i-2] + nums[i]);
        }

        return maxMoneyAtHouse[n-1];
    }
};



int main(){
    vector<int> nums = {2,7,9,3,1};
    Solution solution;
    int maxAmount = solution.rob(nums); 
    cout<<"Max amount is : "<<maxAmount;
    
}
