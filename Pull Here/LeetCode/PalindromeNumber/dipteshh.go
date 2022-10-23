package main

import "fmt"

var reverse int = 0

func revNumber(palNum int) int {
    var remainder int

    for ; palNum > 0; palNum = palNum / 10 {
        remainder = palNum % 10
        reverse = reverse*10 + remainder
    }
    return reverse
}
func main() {

    var palNum int

    fmt.Print("Enter the Number to check Palindrome = ")
    fmt.Scanln(&palNum)

    reverse = revNumber(palNum)
    fmt.Println("The Reverse of the Given Number = ", reverse)

    if palNum == reverse {
        fmt.Println(palNum, " is a Palindrome Number")
    } else {
        fmt.Println(palNum, " is Not a Palindrome Number")
    }
}