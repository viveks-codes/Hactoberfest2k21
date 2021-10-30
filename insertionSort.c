#include<stdio.h>
int main()
{
	int i,j,n,k,l,key,m;
	int arr[100];
	
	printf("Enter the no of elements you want in your array:");
	scanf("%d",&n);
	printf("\n Enter %d elements:",n);
	
	for (i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("\n Unsorted array:");
	
	for(j=0; j<n; j++)
	{
		printf("\n %d",arr[j]);
	}
	
	for(k=1;k<n;k++)
	{
		key = arr[k];
		l=k-1;
		while(l>=0 && arr[l]>key)
		{
			arr[l+1] = arr[l];
			l = l-1;
		}
		arr[l+1]=key;
	}
		                      
	printf("\n Sorted array:");
	
	for(m=0; m<n; m++)
	{
		printf("\n %d",arr[m]);
    }	
	
}
