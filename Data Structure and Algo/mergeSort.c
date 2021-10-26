#include<stdio.h>
#define max 10
int arr[11] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0 };
int b[10];

void merge( int low, int mid, int high)
{
	int l1, l2, i=low;
	
   for(l1 =  low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) 
   {
      if (arr[l1] <= arr[l2])
         b[i] = arr[l1++];
      else
         b[i] = arr[l2++];
   }	
	while (l1<=mid)
	{
		b[i++] = arr[l1++];
	}	
	while (l2 <= high)
	{
		 b[i++] = arr[l2++];
	}
	
	for (i=low; i<high; i++)
	{
		arr[i] = b[i];
    }        
}
void mergesort(int l,int h)
{
	int mid;
	if(l<h)
	{
		mid= (l+h)/2;
		mergesort(l,mid);
		mergesort(mid+1, h);
		merge(l,mid,h);		
	}
}
int main()
{
	int i,j,k,n;
	
	mergesort(0,max);
	
	printf("\n Sorted array:");
	
	for(k=0; k<max; k++)
	{
		printf("\n %d",arr[k]);
	}	
}
