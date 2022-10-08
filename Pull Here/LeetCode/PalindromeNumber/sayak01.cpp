#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        unsigned rx = 0;
        unsigned store = x;
        while (x)
        {
            rx = rx * 10 + x % 10;
            x /= 10;
        }
        return store == rx;
    }
};
