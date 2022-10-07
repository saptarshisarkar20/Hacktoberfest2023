//Longest Substring Without Repeating Characters

class Solution {
public:
//function to check maximum of two numbers
    int max(int a,int b)
    {
        return a>b?a:b;
    }

//function to find length of longest substring

    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0)
            return 0;
        set<char> st;
        int i=0,j=0,ma=0;
        while(j<n)
        {
            if(st.count(s[j])==0)
            {
                st.insert(s[j]);
                ma=max(ma,st.size());
                j++;
            }
            else
            {
                st.erase(s[i]);
                i++;
            }
            
        }
        return ma;
    }
};