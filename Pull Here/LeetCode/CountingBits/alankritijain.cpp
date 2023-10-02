class Solution {
public:
    vector<int> countBits(int n) {
       vector<int> answer(n+1);
       for(int i=1;i<=n;i++){
           if(i%2!=0)
           answer[i]= answer[i>>1]+1;
           else
           answer[i]= answer[i>>1];
       }
       return answer;
        
    }
};
