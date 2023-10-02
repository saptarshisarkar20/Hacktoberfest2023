class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        n = len(nums)
        
        if n == 1:
            return nums[0]
        
        dp = [0] * n
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])
        
        for i in range(2, n):
            # For each house, you can either choose to rob it (nums[i] + dp[i-2])
            # or skip it (dp[i-1])
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1])
        
        return dp[-1]
