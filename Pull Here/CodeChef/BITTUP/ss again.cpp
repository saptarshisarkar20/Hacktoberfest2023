// https://github.com/sayak2k1maruti/competetivePogramming/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    
}

int main()
{
    // your code goes here
    ll t;
    cin >> t;
    for (;t>0;t--){
        ll n;
        cin >> n;
        vector<pair<ll, ll>> x;
        vector<pair<ll, ll>> y;
        multiset<ll> X;
        multiset<ll> Y;
        for (ll i = 0; i < n; ++i){
            ll a, b;
            cin >> a >> b;
            x.push_back({a, b});
            y.push_back({b, a});
            X.insert(a);
            Y.insert(b);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        ll height1 = 0;
        ll height2 = 0;
        ll h1Max = 0;
        ll h1Min = LONG_MAX;
        ll area = LONG_MAX;
        for (ll i = 0; i < n - 1; ++i){
            h1Max = max(h1Max, x[i].second);
            h1Min = min(h1Min, x[i].second);
            height1 = h1Max - h1Min;
            auto it = Y.find(x[i].second);
            Y.erase(it);
            height2 = *Y.rbegin() - *Y.begin();
            ll newArea = (x[i].first - x[0].first) * height1 +
                     (x[n - 1].first - x[i + 1].first) * height2;
            area = min(area, newArea);
        }
        ll width1 = 0;
        ll width2 = 0;
        ll w1Max = 0;
        ll w1Min = LONG_MAX;
        for (ll i = 0; i < n - 1; ++i){
            w1Max = max(w1Max, y[i].second);
            w1Min = min(w1Min, y[i].second);
            width1 = w1Max - w1Min;
            auto it = X.find(y[i].second);
            X.erase(it);
            width2 = *X.rbegin() - *X.begin();
            ll newArea = (y[i].first - y[0].first) * width1 + (y[n - 1].first - y[i + 1].first) * width2;
            area = min(area, newArea);
        }
        if (area == LONG_MAX)
            area = 0;
        cout << area << endl;
    }
    return 0;
}
