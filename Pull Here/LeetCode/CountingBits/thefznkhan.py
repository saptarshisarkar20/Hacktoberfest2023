def countBits(n):
    ans = [0] * (n + 1)

    for i in range(1, n + 1):
        ans[i] = ans[i >> 1] + (i & 1)

    return ans

def main():
    # Test cases
    n1 = 2
    result1 = countBits(n1)
    print(f"Input: {n1}, Output: {result1}")

    n2 = 5
    result2 = countBits(n2)
    print(f"Input: {n2}, Output: {result2}")

if __name__ == "__main__":
    main()
