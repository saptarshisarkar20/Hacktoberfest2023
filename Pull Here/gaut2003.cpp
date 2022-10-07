class Solution {
public:
    bool isPalindrome(int x) {
      int reverse = 0, temp = x;
      while(temp){
        reverse = reverse*10 + (temp%10);
        temp /= 10;
      }
      
      if(reverse == x) return true;
      else return false;
    }
};
