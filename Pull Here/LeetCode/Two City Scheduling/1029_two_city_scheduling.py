class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:

        n = len(costs) // 2
        dp = {}

        def dfs(a, b):
            if (a, b) in dp:
                return dp[(a, b)]

            if (a + b) >= len(costs):
                return 0
            if a >= n:
                return costs[a + b][1] + dfs(a, b + 1)
            if b >= n:
                return costs[a + b][0] + dfs(a + 1, b)

            first = costs[a + b][0] + dfs(a + 1, b)
            second = costs[a + b][1] + dfs(a, b + 1)

            dp[(a, b)] = min(first, second)
            return min(first, second)

        return dfs(0, 0)
