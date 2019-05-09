
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int n,m,x,y,t;
		double a,b,c,d;
		Scanner sc = new Scanner(System.in);
		t = sc.nextInt();
		while(t-- > 0) {
			n = sc.nextInt();
			m = sc.nextInt();
			x = sc.nextInt();
			y = sc.nextInt();
			a = (double)(n-1)/x;
			//System.out.print(a);
			b = (double)(n-2)/x;
			c = (double)(m-1)/y;
			d = (double)(m-2)/y;
			if(Math.abs(a - (int)a) == 0 && Math.abs(c - (int)c) == 0) {
				if(1 + a*x == n && 1 + c*y == m) {
					System.out.println("Chefirnemo");
				}
				else {
					System.out.println("Pofik");
				}
				continue;
			}
			if(Math.abs(b - (int)b) == 0 && Math.abs(d - (int)d) == 0) {
				if(2 + (Math.abs(b*x)) == n && 2 + (Math.abs(d*y)) == m) {
					System.out.println("Chefirnemo");
				}
				else {
					System.out.println("Pofik");
				}
				continue;
			}
			System.out.println("Pofik");
		}
	}
}

