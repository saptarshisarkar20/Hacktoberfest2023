class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = [0] * (n + 1)
        for i in range(1, n + 1):
            ans[i] = ans[i & (i - 1)] + 1
        return ans



solution = Solution()
n = 5
result = solution.countBits(n)
print(result)  # Output: [0, 1, 1, 2, 1, 2]
