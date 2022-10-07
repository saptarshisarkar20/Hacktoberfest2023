here is the code for the question

#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define F first
#define S second
#define pb push_back
#define in insert

ll area(int n, vector <pair<ll, ll>> co_ord, multiset <ll> uni) {
    ll dirMax = 0, dirMin = LONG_MAX, d1, d2, calMaxArea = LONG_MAX;
	ll i = 0;

    while (i < n - 1) {
		
		dirMin = min(co_ord[i].second, dirMin);
        dirMax = max(co_ord[i].second, dirMax);
		d1 = dirMax - dirMin;

		multiset <ll>::iterator itr = uni.find(co_ord[i].second);
		uni.erase(itr);

        multiset <ll>::reverse_iterator fromBack = uni.rbegin();
        multiset <ll>::iterator fromFront = uni.begin();
        d2 = *fromBack - *fromFront;

        ll firstCoord = d1 * (co_ord[i].first - co_ord[0].first);
        ll secondCoord = d2 * (co_ord[n-1].first - co_ord[i+1].first);

		ll calNewArea = firstCoord + secondCoord;
		calMaxArea = min(calMaxArea, calNewArea);

        i = i + 1;
	}

    return calMaxArea;
}

void solve() 
{
	ll n, a, b, i;
	ll maxArea = LONG_MAX;

	cin >> n;

	multiset <ll> xUni;
	multiset <ll> yUni;

    vector <pair<ll, ll>> X;
	vector <pair<ll, ll>> Y;

    i = 0;
    while (i < n) {
        cin >> a >> b;

		yUni.in(b);
        xUni.in(a);

		Y.pb({b, a});
        X.pb({a, b});

        i++;
    }

    if (n == 1)
    {
        cout << '0' << endl;
    }
    else
    {
        sort(Y.begin(), Y.end());
        sort(X.begin(), X.end());

        maxArea = area(n, X, yUni);
        
        ll wmax = 0, wmin = LONG_MAX, w1, w2;

        for (int i = 0; i < n - 1; i++) {
            wmax = max(Y[i].second, wmax);
            wmin = min(Y[i].second, wmin);
            w1 = wmax - wmin;

            multiset <ll>::iterator it = xUni.find(Y[i].second);
            xUni.erase(it);

            multiset <ll>::reverse_iterator fromBack = xUni.rbegin();
            multiset <ll>::iterator fromFront = xUni.begin();   

            w2 = *fromBack - *fromFront;

            ll firstCoord = w1 * (Y[i].F - Y[0].F);
            ll secondCoord = w2 * (Y[n-1].F - Y[i+1].F);

            ll newarea = firstCoord + secondCoord;

            maxArea = min(maxArea, newarea);
        }
        
        cout << maxArea << endl;
    }

}

int main()
{
    ll testcase;
    // testcase = 1;
    cin >> testcase;
    while (testcase > 0) {
        solve();
        testcase--;
    }
    return 0;
}
