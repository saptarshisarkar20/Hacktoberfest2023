class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0){
            return false;
        }
        
        int num = x, opposite = 0, remainder = 0;
		
        while(x != 0){
            remainder = x%10;
            opposite = opposite*10 + remainder;
            x /= 10;
        }       

        if(num == opposite){
            return true;
        }
        else{
            return false;
        }
    }
};
