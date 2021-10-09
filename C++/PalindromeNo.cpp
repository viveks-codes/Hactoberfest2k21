#include<iostream>


int main()
{
	int n,number,digit,rev_integer=0;
	std::cout<< "Enter Any Number to check it is palindrome or not";
	std::cin >>number;
	n=number;
	do
	
	{
		digit = number % 10;
		rev_integer = (rev_integer * 10) + digit;
		number =number/10;
		 
		
	}while(number!=0);
	
	
	if(n == rev_integer)
	{
		std::cout<<"Entered No is an Palindrome Number...";
	}
	else
	{
		std::cout<<"Entered No is not an Palindrome Number..";
	}
	
	return 0;
}

