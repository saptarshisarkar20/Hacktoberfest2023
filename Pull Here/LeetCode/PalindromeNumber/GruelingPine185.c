// compile with: gcc Pull\ Here/LeetCode/PalindromeNumber/GruelingPine185.c
// run with: ./a.out

#include <stdio.h>


int is_palindrome(int _num) {
    if(_num < 10 || ((_num % 10 == 0) && _num != 0)) return 0;

    int rev = 0;
    int rem = 0;

    while(_num != 0) {
        rem = _num % 10;
        rev *= 10 + rem;
        _num /= 10;
    }

    return (_num == rev);
}

int main(int _argc, char** _argv) {
    int raw;
    printf("Enter an integer: ");
    scanf("%d", &raw);
    printf("%d\n", is_palindrome(raw));
    return 0;
}
