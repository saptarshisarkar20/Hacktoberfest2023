class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        long int rev = 0, num = x;
        while(x>0){
            int y = x%10;
            x /= 10;
            // if(rev*10 >= 2147483648) rev = 0;
            rev = rev*10 + y;
        }
        
        if(rev == num) return true;
        
        return false;
    }
};
