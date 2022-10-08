class Solution:
    def isPalindrome(self, x:int):
        tmp = x
        reverse = 0

        while x>0:
            i = x % 10
            reverse = reverse * 10 + i
            x = x // 10

        return tmp == reverse


if __name__ == '__main__':
    print (Solution().isPalindrome(121))
    print (Solution().isPalindrome(-121))
    print (Solution().isPalindrome(10))