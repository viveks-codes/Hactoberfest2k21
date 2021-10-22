#include<stdio.h>

int main()
{
  #takin an array for example
	int arr[] = {34,45,56,23,7,1,79};
	int t,i,j,k;
	int n=7;
	
	
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if (arr[j]>arr[j+1])
			{
				t= arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
				
			}
		}
	}
	
	printf("\n Array after sorting:");
	
	for(k=0; k<n; k++)
	{
		printf("\n %d",arr[k]);
	}
	
}
