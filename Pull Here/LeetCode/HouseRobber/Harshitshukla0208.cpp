#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        // Initialize an array to store maximum robbed amount up to each house
        vector<int> dp(n, 0);

        // Base cases
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // Fill up the dp array iteratively
        for (int i = 2; i < n; i++)
        {
            // Either rob the current house and add the amount from two houses ago,
            // or skip the current house and keep the amount from the previous house.
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }
};