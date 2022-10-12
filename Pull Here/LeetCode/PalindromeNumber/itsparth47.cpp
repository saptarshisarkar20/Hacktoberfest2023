bool isPalindrome(int x) {
    int temp=x;
    int k=x;
    int y=0;
    int ct=-1;
    while(temp)
    {
        ct++;
        temp/=10;
    }
    while(x)
    {
        y+=(x%10)*(pow(10,ct));
        x/=10;
        ct--;
    }
    if(k<0||k!=y)
    return false;
    else
    return true;
}  
