#include<iostream>


using namespace std;
int main()
{	
 int m,n,first[10][10],second[10][10];
 
 cout<<"Enter Number of Rows And Columns:\n";
 cin>>m>>n;
 cout<<"Enter Elements of 1st Matrix\n";
 
 for(int i=0;i<m;i++)
 {
 	for(int j=0;j<n;j++)
 	{
 		cin>>first[i][j];
	 }
 }
cout<<"All The Matrix Elements are:";

for(int i=0;i<m;i++)
{
	for(int j=0;j<n;j++)
	{
		cout<<" ";cout<<first[i][j]<<" ";
	}
	cout<<"\n";
}
return 0;
}


