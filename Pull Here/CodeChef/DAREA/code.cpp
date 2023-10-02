#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb(e) push_back(e)
#define sv(a) sort(a.begin(), a.end())
#define sa(a, n) sort(a, a + n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define fo(i, a, b) for (ll i = a; i < b; i++)
#define unique(v) v.erase(std::unique(v.begin(), v.end()), v.end());
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        ll c[n];
        fo(i, 0, n)
        {
            cin >> c[i];
        }

        ll ans = b - 1;
        ll num = 1;
        fo(i, 0, n)
        {
            if (c[i] + num < a)
            {
                num += c[i];
                // cout<<num<<endl;
            }
            else if (c[i] + num >= a)
            {
                num = a;
            }
            ans += num - 1;
            num = 1;
            // cout<<num<<endl;
        }

        cout << ans + 1 << endl;
        // cout<<endl;
    }
    return 0;
}
