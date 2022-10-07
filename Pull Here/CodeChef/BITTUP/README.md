# Bitwise Tuples
Problem Code: BITTUP
## LINK : https://www.codechef.com/JUNE21B/problems/BITTUP
## Problem:
Chef has two numbers N and M. Help Chef to find number of integer N-tuples (A1,A2,…,AN) such that 0≤A1,A2,…,AN≤2^M−1 and A1&A2&…&AN=0, where & denotes the bitwise AND operator.

Since the number of tuples can be large, output it modulo 10^9+7.
## Input:
  - The first line contains a single integer T denoting the number of test cases. The description of T test cases follows.
  - The first and only line of each test case contains two integers N and M
 ## Output:
For each test case, output in a single line the answer to the problem modulo  10^9+7
## Constraints:
 - 1≤T≤10^5
 - 1≤N,M≤10^6
 ## Sample Input 1:
```
4
1 2
2 2
4 2
8 4
```
## Sample Output1:
```
1
9
225
228250597
```

## Explamnation:
  - Test Case 1 : The only possible tuple is (0).
  - test Case 2 : The tuples are (0,0), (0,1), (0,2), (0,3), (1,0), (2,0), (3,0), (1,2), (2,1).
