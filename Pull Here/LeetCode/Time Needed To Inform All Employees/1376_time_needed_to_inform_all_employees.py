class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:

        adj = defaultdict(list)

        for i in range(n):
            if manager[i] != -1:
                adj[manager[i]].append((informTime[i], i))

        time = {x: float('inf') for x in range(n)}

        heap = [(0, headID)]
        visited = set()

        while heap:
            w1, n1 = heappop(heap)

            if n1 in visited:
                continue

            time[n1] = min(time[n1], w1)
            visited.add(n1)

            for w2, n2 in adj[n1]:
                if n2 not in visited:
                    heappush(heap, (w1 + w2, n2))

        return max(time.values()) + informTime[headID]

