#include<iostream>
#include<cmath>
#define ull unsigned long long int
#define ll long long int
ull p = pow(10,9)+7;
using namespace std;
int calculate(ull n,ull m){
    //we want to calculate (2^n - 1)^m  mod p
    
    /*Calculating : (2^n - 1)mod p*/
    ull r;
    unsigned long long u = 1, w = 2;
    while (n != 0){
        if ((n & 0x1) != 0){
            u = (u * w) % p; /* (mul-rdx) */
        }
        if ((n >>= 1) != 0){
            w = (w * w) % p; /* (sqr-rdx) */
        }
    }
    r = (unsigned long) u;
    r = (r == 0) ? (p - 1) : (r - 1);
    //r = (2^n - 1)mod p


    /*Now calculating  final result = (2^n - 1)^m  mod p*/
    ull res = 1;     // Initialize result
    if (r == 0) return 0; // In case x is divisible bm p;
    while (m > 0){
        // If m is odd, multiplm x with result
        if (m & 1)
            res = (res*r) % p;
        // m must be even now
        m = m>>1; // m = y/2
        r = (r*r) % p;
    }
    return res;
}
int main(){
    ull t;
    cin >> t;
    for(;t>0;t--){
        ull n,m;
        cin >> n >>m;
        cout << calculate(n,m) << endl;
    }
    return 0;
}
