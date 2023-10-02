class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans (n+1);
        ans[0] = 0;
        for(int i=1; i<n+1; i++)
        {
            int s = ans[i/2];
            if(i%2 != 0)
                s+=1;
            ans[i]=s;
        }
        return ans;
};
