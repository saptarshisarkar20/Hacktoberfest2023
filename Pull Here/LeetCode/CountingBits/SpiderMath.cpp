#include <vector>
#include <iostream>
using namespace std;

class Bit {
public:
    vector<int> countTheBits(int n) {
        vector<int> a(n + 1);
        a[0] = 0;
        for (int i = 1; i <= n; ++i) {
            a[i] = a[i >> 1] + (i & 1);
        }
        return a;
    }
};


void main() {
    Bit soln;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "\n";
    vector<int> result = solution.countBits(n);
    for (int i = 0; i <= n; ++i) {
        cout << result[i] << " ";
    }
}
