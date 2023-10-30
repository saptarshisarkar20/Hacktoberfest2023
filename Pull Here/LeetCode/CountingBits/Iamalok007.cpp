#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> ans;
        for (int i = 0; i <= n; i++) {
            int temp = i;
            int count = 0;
            while (temp > 0) {
                if (temp % 2 != 0) {
                    count++;
                }
                temp = temp / 2;
            }
            ans.push_back(count);
        }
        return ans;
    }
};

int main() {
    int n;
    std::cout << "Enter a number (n): ";
    std::cin >> n;

    Solution solution;
    std::vector<int> result = solution.countBits(n);

    std::cout << "Count of 1s in binary representation from 0 to " << n << ":\n";
    for (int i = 0; i <= n; i++) {
        std::cout << i << ": " << result[i] << "  ";
    }

    return 0;
}


/*output:
Enter a number (n): 5
Count of 1s in binary representation from 0 to 5:
0: 0  1: 1  2: 1  3: 2  4: 1  5: 2  
*/