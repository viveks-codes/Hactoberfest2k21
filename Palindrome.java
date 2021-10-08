import java.util.Scanner;
class palindrome
{
	public static void main(String args[])
	{
		String S1 = new String();
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter the String : ");
		String S = scan.next();
		int n = S.length();
		for(int i = 0; i < n; i++)
		{
			S1 = S1.concat(String.valueOf(S.charAt(n-1-i)));			
		}
		if(S.equals(S1))
			System.out.println("It is palindrome.");
		else
			System.out.println("It is not Palindrome.");
		
	}
}
