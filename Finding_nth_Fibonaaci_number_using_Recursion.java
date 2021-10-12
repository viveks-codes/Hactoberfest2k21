// Fibonacci series is the series of numbers in which each number is equal to the sum 
// of its preceding two numbers 
// Fibonacci series : 0,1,1,2,3,5,8,13,...
// Here 0th fibonacci number is 0,
// 1st fibonacci number is 1, etc..
// This is the simple java program to find the nth fibonacci number using Recursion

import java.util.*;
public class Main
{
	public static void main(String[] args) {
		System.out.println(Fibbonacci(7));
	}
	public static int Fibbonacci(int n)
	{
	    if(n < 2)
	    {
	        return n;
	    }
	    return Fibbonacci(n - 1) + Fibbonacci(n - 2);
	}
}
