# Python Solution for SHROUTE

def solve():
    n, k = map(int, input().split())
    stations = list(map(int, input().split()))
    l_r, r_l = [-1] * n, [-1] * n
    dist = train_avail = 0
    for i in range(n):
        if (i == 0):
            l_r[i] = 0
        if (stations[i] == 1):
            train_avail = 1
            dist = 0
            l_r[i] = 0
        if (stations[i] == 2):
            l_r[i] = 0
        if (stations[i] != 1 and train_avail):
            dist += 1
            l_r[i] = dist
    dist = train_avail = 0
    for i in range(n - 1, -1, -1):
        if (i == 0):
            r_l[i] = 0
        if (stations[i] == 2):
            train_avail = 1
            dist = r_l[i] = 0
        if (stations[i] == 1):
            r_l[i] = 0
        if (stations[i] != 2 and train_avail):
            dist += 1
            r_l[i] = dist
    ans = []
    for i in list(map(int, input().split())):
        a1 = l_r[i - 1]
        a2 = r_l[i - 1]
        if (a1 == a2 == -1):
            ans.append(-1)
        else:
            if (a1 == -1):
                ans.append(a2)
            elif (a2 == -1):
                ans.append(a1)
            else:
                ans.append(min(a1, a2))
    print(*ans)


def main():
    t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
