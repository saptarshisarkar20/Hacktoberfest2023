#include<bits/stdc++.h>
using namespace std;
#define   ll            long long
#define   pb            push_back
#define   fastio        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define   yes 	        cout<<"YES"<<endl
#define   no 	 	    cout<<"NO"<<endl

int main()
{

	ll mysoln;
	cin>>mysoln;

	while(mysoln--)
	{
		 long long n,soln=1,k=1;
        cin>>n;
       long long a[n];
         multiset<int>cop;
        for (int i =0;i<n;i++)
		{
		    cin>>a[i];
		    cop.insert(a[i]);
		}
		
		while(cop.size()>0)
		{
	       	auto i = cop.lower_bound(k);
	       	if(i!=cop.end())
	       	{
	          	cop.erase(i);
	          	k++;
	       	}
	       	else
	       	{
	       	    k=1;
	       	    soln++;
	       	}
	    }
		cout<<soln<<endl;
	}
return 0;
}
