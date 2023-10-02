def countBits(n):
    # Initialize a list to store the count of 1 bits for each number
    dp = [0] * (n + 1)

    for i in range(1, n + 1):
        # To count the 1 bits of i, we use the result for i // 2 (right shift) and add 1 if i is odd.
        dp[i] = dp[i // 2] + (i % 2)

    return dp

# Example usage:
n = 5
result = countBits(n)
print(result)  # Output: [0, 1, 1, 2, 1, 2]
