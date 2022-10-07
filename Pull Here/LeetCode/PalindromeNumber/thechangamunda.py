"""
Problem Statement:
Given an integer x, return true if x is palindrome integer.
An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Constraints:
-231 <= x <= 231 - 1

Follow up: Could you solve it without converting the integer to a string?
"""
'------------------------------------------------------------------------------------------------------------'
"Solution:"

n=int(input("Enter number:"))
temp=n
rev=0
while(n>0):
    num=n%10
    rev=rev*10+num
    n=n//10
if(temp==rev):
    print("The number is a palindrome.")
else:
    print("The number isn't a palindrome.")

"""
Program Explanation
1. User must first enter the value of the integer and store it in a variable(n).
2. The value of the integer is then stored in another temporary variable(temp).
3. The while loop is used and the last digit of the number is obtained by using the modulus operator(num=n%10).
4. The last digit is then stored at the ones place, second last at the tens place and so on.
5. The last digit is then removed by truly dividing the number with 10.
6. This loop terminates when the value of the number is 0.
7. The reverse of the number is then compared with the integer value stored in the temporary variable
(if(temp==rev)).
8. If both are equal, the number is a palindrome.
9. If both arent equal, the number isnt a palindrome.
10. The final result is then printed.

"""
