import java.util.Scanner;
class explict
{
	public static void main(String args[])
	{
		float a;
		System.out.println("Enter the number to convert:");
		Scanner scan = new Scanner(System.in);
		a = scan.nextFloat();
		System.out.println("Number is Integer.");
		System.out.println("Number before conversion :"+ a);
		int b = (int)a;
		System.out.println("Number is Decimal.");
		System.out.println("Number after conversion:" + b);
	}
}
class implict
{
	public static void main(String args[])
	{
		int a;
		System.out.println("Enter the number to convert:");
		Scanner scan = new Scanner(System.in);
		a = scan.nextInt();
		System.out.println("Number is Integer.");
		System.out.println("Number before conversion :"+ a);
		float b = a;
		System.out.println("Number is Decimal.");
		System.out.println("Number after conversion:" + b);
	}
}
