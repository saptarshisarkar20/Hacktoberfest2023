class Solution 
{
    public int[] countBits(int n) 
    {
        int arr[]=new int[n+1];
        for(int i=0;i<=n;i++)
        {
            int count=0;
// here only it is extra that is built in function for coversion of decimal to binary
           String temp=Integer.toBinaryString(i);
           for(int j=0;j<temp.length();j++)
           {
            if(temp.charAt(j)=='1')
            {
                count++;
            }
           }
           arr[i]=count;
        }
        return arr;
    }
}
