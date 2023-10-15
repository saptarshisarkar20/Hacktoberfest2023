//Java Script code to count the numbers
/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    // return function() {
    //     return (n)=> n+1
    // };
    return ()=> n++
            
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
