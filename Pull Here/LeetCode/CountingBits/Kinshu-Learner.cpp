#include <iostream>
#include <vector>
using namespace std;

// This is an O(n) time complexity solution.

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int highBitsCount = ans[i >> 1];
            int leastSignificantBit = i & 1;
            ans[i] = highBitsCount + leastSignificantBit;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int n = 5;

    vector<int> result = solution.countBits(n);

    cout << "Counts of set bits for numbers from 0 to " << n << ":" << endl;
    for (int i = 0; i <= n; ++i) {
        cout << i << ": " << result[i] << " set bit(s)" << endl;
    }

    return 0;
}
