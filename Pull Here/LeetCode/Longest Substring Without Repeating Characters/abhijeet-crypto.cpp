class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      if (s == "") {
        return 0;
      }
      set <char> my_set;
      int start = 0;
      int endd = 0;
      int maxx = 0;
      while (endd<s.length()) {
        if (my_set.count(s[endd])) {
          my_set.erase(s[start]);
          start++;
        }
        else{  
          my_set.insert(s[endd]);
          endd++;
          maxx=max(maxx,(int)my_set.size());
        }
      }
      return maxx;
    }
};