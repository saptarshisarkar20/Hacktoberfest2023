#include<stdio.h>
//#include<iostream>
#define ll long long int
using namespace std;
int main(){
    ll t;
    scanf("%lld",&t);
    for(;t>0;t--){
        ll m,n;
        scanf("%lld %lld",&n,&m);
        //cin >> n >> m;
        ll arr[n+1],shortest[n+1];
        for(ll i=1;i<=n;i++){
            scanf("%lld",&arr[i]);
            //cin >> arr[i];
        }

        //Towards Right trains
        ll flag = -1;
        for(ll i=1;i<=n;i++){
            if(arr[i] == 1){
                flag = i;
            }
            shortest[i] =  (flag == -1) ? -1 : (i-flag);
        }

        //Towards Left trains
        flag = -1;
        for(ll i=n;i>0;i--){
            if(arr[i] == 2){
                flag = i;
            }
            if(flag != -1){
                if(shortest[i] == -1){
                    shortest[i] = flag-i;
                }else{
                    shortest[i] = shortest[i] < (flag-i) ? shortest[i] : (flag-i);
                }
            }
        }

        for(ll i=0;i<m;i++){
            ll temp;
            scanf("%lld",&temp);
            //cin >> temp;
            if(temp == 1){
                printf("0 ");
                //cout << "0 ";
            }else{
                printf("%lld ",shortest[temp]);
                //cout << shortest[temp] << ' ';
            }
        }
        printf("\n");
    }
    return 0;
}
