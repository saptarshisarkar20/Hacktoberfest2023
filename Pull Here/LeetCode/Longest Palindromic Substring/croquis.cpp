#include <bits/stdc++.h>
class LongestPalindrome {
public:
    string main(string s) {
        int n=s.length();
        
        int maxi=1;
        
        int start=0;
        int end=0;
        
        int l,r;
        
        for(int i=0;i<n;i++){
    
            l=i-1;
            r=i+1;
            
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    if(r-l+1>maxi){
                        maxi=r-l+1;
                        start=l;
                        end=r;
                    }
                    l--;
                    r++;
                }else{
                    break;
                }
            }
            
            l=i-1;
            r=i;
            
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    if(r-l+1>maxi){
                        maxi=r-l+1;
                        start=l;
                        end=r;
                    }
                    l--;
                    r++;
                }else{
                    break;
                }
            }
        }
        
        string ans="";
        for(int i=start;i<=end;i++){
            ans+=s[i];
        }
        return ans;
    }
};