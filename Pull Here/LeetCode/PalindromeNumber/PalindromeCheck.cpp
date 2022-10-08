#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isPal(int n)
{
    int rev=0;
    int temp=n;
    while(temp>0){
        int ld=temp%10;
        rev=(rev*10)+ld;
        temp=temp/10;
    }
    if(rev==n)
            return true;
        else
            return false;
}
int main()
{
    int a;
    cin>>a;
    if
(isPal(a))
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;

    return 0;
}