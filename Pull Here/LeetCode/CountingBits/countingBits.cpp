class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};
