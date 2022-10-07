#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;


// ########################################

class Solution
{
  // knapsack problem in Dynamic programming
public:
  int dp[1001][1001];
  // memset(dp, -1, sizeof(dp));
  //Function to return max value that can be put in knapsack of capacity W.
  int knapsack(int W, int wt[], int val[], int n)
  {
    // Your code here
    if (W == 0 || n == 0)
    {
      return 0;
    }
    if (!(dp[W][n] == (-1)))
    {
      return dp[W][n];
    }
    else
    {
      if (wt[n - 1] > W)
      {
        dp[W][n] = knapsack(W, wt, val, n - 1);
        return dp[W][n];
      }
      else
      {
        dp[W][n] = max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1), knapsack(W, wt, val, n));
        return dp[W][n];
      }
    }
  }
};


//##################################################

int main()
{

  return 0;
}
