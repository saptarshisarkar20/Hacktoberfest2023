#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
int main  () {
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,right=1000000,left=1000000;
        cin>>n>>m;
        ll arr1[n],arr2[m];
        for(ll i=0;i<n;i++)
        {
            cin>>arr1[i];
        }
        for(ll i=0;i<m;i++)
        {
            cin>>arr2[i];
        }
        for (ll i = 0; i < n; i++)
        {
            if(arr1[i]==1)
            arr1[i]=1000000;

            if(arr1[i]==2)
            arr1[i]=-1000000;
        }
        for (ll i = 0; i < n; i++)
        {
            if(arr1[i]==1000000)
            right = i;

            if(arr1[i]==-1000000)
             continue;
            
            if(arr1[i]==0)
            {
                if(right!=1000000)
                arr1[i]=i-right;
            }
        } 
        for (ll i = n-1; i >=0; i--)
        {
            if(arr1[i]==-1000000)
            left = i;

            else if(arr1[i]==1000000)
             continue;
            
            else
            {
                if(left!=1000000)
                {
                if(arr1[i]!=0)
                arr1[i]=min((left-i),arr1[i]);

                else
                arr1[i]=left-i;
                }
            }
        }  
        /*  for(int i=0;i<n;i++)
        {
            cout<<arr1[i]<<" ";
        }  */
           for(int i=0;i<m;i++)
        {
            int j= arr2[i]-1;
             if(arr1[j]==-1000000||arr1[j]==1000000||j==0)
             cout<<"0"<<" ";

             else if(arr1[j]==0)
             {
                  cout<<"-1"<<" ";
             }
             else
             cout<<arr1[j]<<" ";
        }  
         cout<<"\n"; 
    }        
return 0;
}
