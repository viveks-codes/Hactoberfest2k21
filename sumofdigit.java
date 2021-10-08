import java.util.Scanner;
class sumofdigit
{
	public static void main(String args[])
	{
		int a,fact=1,d,sum=0;
		System.out.print("Enter the number : ");
		Scanner s = new Scanner(System.in);
		a = s.nextInt();
		while(a>0)
		{
			d = a%10;
			a = a/10;
			sum =sum + d;
		} 
		System.out.println("Sum of digit is = " + sum);
	} 
}
