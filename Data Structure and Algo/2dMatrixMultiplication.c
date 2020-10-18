#include<stdio.h>
void main()
{
int a[100][100];
int b[100][100];
int c[100];
int m[100][100];
int r1,r2,c1,c2,sum;
scanf("%d",&r1);
scanf("%d",&c1);
scanf("%d",&r2);
scanf("%d",&c2);
for(int i=0;i<r1;i++)
{
	for(int j=0;j<c1;j++)
	{
	scanf("%d",&a[i][j]);
	
	}
}
for(int i=0;i<r2;i++)
{	
	for(int j=0;j<c2;j++)
		{
		scanf("%d",&b[i][j]);
		
		}
}

for(int i=0;i<r1;i++)
{
	for(int j=0;j<c2;j++)
	{
	 sum=0;
 	 for(int k=0;k<r2;k++)
 	 {
 	 
 	 c[k]=a[i][k]*b[k][j];
 	 sum+=c[k];
 	 
 	 }
 	 m[i][j]=sum;
 	 
	}
}
for(int i=0;i<r1;i++)
{
	for(int j=0;j<c2;j++)
	{
	printf("%d ",m[i][j]);
	}
printf("\n");
}
}
