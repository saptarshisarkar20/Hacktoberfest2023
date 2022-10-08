def palindrome(x):
    num=0
    p=x
    while(x>0):
        r=x%10
        x=int(x/10)
        num=num*10+r
    if(num==p):
        print("true")
    else:
        print("false")
#main
x=int(input("x = "))
palindrome(x)