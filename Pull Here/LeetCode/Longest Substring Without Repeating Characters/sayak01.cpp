class Solution {
public:
    int lengthOfLongestSubstring(string S){
        if(S.length()==0){
            return 0;
        }
        vector<int> arr(128,-1);
        int n = S.length();
        int left = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(arr[S[i]] == -1){
                arr[S[i]] = i;
            }else if(arr[S[i]] < left){
                arr[S[i]] = i;
            }else{
                left = arr[S[i]] + 1;
                arr[S[i]] = i;
            }
            ans = max(ans,i-left+1);
        }
        return ans;
    }
};
