class Solution:
    def getFood(self, grid: List[List[str]]) -> int:

        rows, cols = len(grid), len(grid[0])
        start, end = None, set()

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == '*':
                    start = (r, c)
                if grid[r][c] == '#':
                    end.add((r, c))

        if not start or not end:
            return -1

        q, visited = deque([start]), set()
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]

        dist = 0
        while q:
            for _ in range(len(q)):
                r, c = q.popleft()

                if (r, c) in end:
                    return dist

                if (r, c) in visited:
                    continue

                visited.add((r, c))

                for dr, dc in directions:
                    nr, nc = dr + r, dc + c

                    if (nr < 0 or nr == rows or nc < 0 or nc == cols or
                            grid[nr][nc] == 'X'):
                        continue
                    q.append((nr, nc))
            dist += 1

        return -1