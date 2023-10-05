#include <vector>
#include <iostream>

class Bit {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> a(n + 1);
        a[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            a[i] = a[i >> 1] + (i & 1);
        }
        
        return a;
    }
};

int main() {
    Bit solution;
    int n;
    
    std::cout << "Enter a number: ";
    std::cin >> n;

    std::vector<int> result = solution.countBits(n);

    for (int i = 0; i <= n; ++i) {
        std::cout << result[i] << " ";
    }

    return 0;
}
