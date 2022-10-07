# Python Solution for BITTUP

def solve():
    n, m = map(int, input().split())
    mod = int(1e9) + 7
    print(pow(pow(2, n, mod) - 1, m, mod))


def main():
    t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
