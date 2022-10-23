class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0) return false;
        vector<int> s;
        while(x!=0){
            s.push_back(x%10);
            x/=10;
        }
        vector<int> n;
        n=s;
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            if(s[i]!=n[i]) return false;
        }
        return true;
    }
};