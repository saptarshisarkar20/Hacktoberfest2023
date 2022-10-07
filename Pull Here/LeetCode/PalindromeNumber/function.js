const isPalindrome = (num) => {
  if (num < 10) {
    return false;
  }

  let i = 0;
  const numByString = num.toString();
  while (i < numByString.length - 1 - i) {
    if (numByString[i] !== numByString[numByString.length - 1 - i]) {
      return false;
    }
    i++;
  }

  return true;
}

console.log(isPalindrome(323)); // true
console.log(isPalindrome(123)); // false
console.log(isPalindrome(-123)); // false
console.log(isPalindrome(3)); // false
console.log(isPalindrome(1221)); // true
