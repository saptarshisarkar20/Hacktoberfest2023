
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static long com(long n,long m){
        long val=1;
        while(m>0){
            if((m & 1)==1){
                val=(val*n)%1000000007;
            }
            n=(n*n)%1000000007;
            m/=2;
        }
        return val;
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		try {
		      Scanner sc=new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0){
                int n = sc.nextInt();
                int m = sc.nextInt();
                
                long x=com(2,n)-1;
                long count=com(x,m);
                System.out.println(count);
            }
		} catch(Exception e) {
		} finally {
		}
	}
}
