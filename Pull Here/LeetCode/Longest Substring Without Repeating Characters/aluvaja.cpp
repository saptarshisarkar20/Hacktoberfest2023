class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int i, j=0, mx = 0;
    
        for(i=0; i<s.length(); i++){
            if(st.find(s[i]) != st.end()){
                mx = max(mx, i-j);
                while(st.find(s[i]) != st.end()){
                    st.erase(s[j++]);
                }
            }
            st.insert(s[i]);
        }
        mx = max(mx, i-j);
        return mx;
    }
};class Solution33 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int i, j=0, mx = 0;
    
        for(i=0; i<s.length(); i++){
            if(st.find(s[i]) != st.end()){
                mx = max(mx, i-j);
                while(st.find(s[i]) != st.end()){
                    st.erase(s[j++]);
                }
            }
            st.insert(s[i]);
        }
        mx = max(mx, i-j);
        return mx;
    }
};class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int i, j=0, mx = 0;
    
        for(i=0; i<s.length(); i++){
            if(st.find(s[i]) != st.end()){
                mx = max(mx, i-j);
                while(st.find(s[i]) != st.end()){
                    st.erase(s[j++]);
                }
            }
            st.insert(s[i]);
        }
        mx = max(mx, i-j);
        return mx;
    }
};class Solution1{
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int i, j=0, mx = 0;
    
        for(i=0; i<s.length(); i++){
            if(st.find(s[i]) != st.end()){
                mx = max(mx, i-j);
                while(st.find(s[i]) != st.end()){
                    st.erase(s[j++]);
                }
            }
            st.insert(s[i]);
        }
        mx = max(mx, i-j);
        return mx;
    }
};
