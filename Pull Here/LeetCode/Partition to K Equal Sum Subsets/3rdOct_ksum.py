# Denote by dp[mask] possibility to put numbers with mask mask into our subsets. 
# In more detais: we return -1 if this partition is not possible and we return t >= 0, 
# if it is possible, where t is reminder when we divide sum of all used numbers so far 
# by basket: value, of how many we need to put in each group. Then to check if we can do it,
#   we need to check the last number we put and check O(n) possible options, where n is number of nums.

# Example: Imagine that we have mask = 01011, it means that we already taken numbers a0, a1, a3 
#   (we start from end bits). Then to evaluate dp[mask], we need to look at 01010, 01001, 00011 
#   masks and try to add missing bit.

# Complexity

# Overall time complexity is (2^n*n) and space complexity is O(2^n).

# Code

class Solution:
    def canPartitionKSubsets(self, nums, k):
        N = len(nums)
        nums.sort(reverse = True)

        basket, rem = divmod(sum(nums), k)
        if rem or nums[0] > basket: return False

        dp = [-1] * (1<<N) 
        dp[0] = 0
        for mask in range(1<<N):
            for j in range(N):
                neib = dp[mask ^ (1<<j)]
                if mask & (1<<j) and neib >= 0 and neib + nums[j] <= basket:
                    dp[mask] = (neib + nums[j]) % basket
                    break

        return dp[-1] == 0

