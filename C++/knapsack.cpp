// KNAPSACK PROBLEM
// (GREEDY METHOD)
// This Code is Contributed by Tushar Tiwari
#include<iostream.h>
#include<conio.h>
//knapsack problem
void main()
{
	int n,value[10];
	int wt[10];
	cout<<endl<<"enter the number of objects"<<endl;
		cin>>n;

	cout<<"enter the weights of objects"<<endl;
	for(int x=0;x<n;x++)
		cin>>wt[x];

	cout<<"enter the value of objects"<<endl;
	for(x=0;x<n;x++)
		cin>>value[x];

	float rto[10] = {0};
	for(x=0;x<n;x++)
		rto[x] = (float)value[x]/wt[x];
	// insertion sort on rto.
		for(int k=1;k<n;k++)
	{
		float temp = rto[k];
		int vtemp = value[k];
		int wtemp = wt[k];
		int j=k-1;
			while(j>=0&&temp>=rto[j])
			{
				rto[j+1] = rto[j];
				value[j+1] = value[j];
				wt[j+1] = wt[j];
				j--;
			}
			rto[j+1] = temp;
			value[j+1] = vtemp;
			wt[j+1] = wtemp;
	}
	cout<<endl<<"the sorted ratio of value by weight is "<<endl;
	for(x=0;x<n;x++)
			cout<<rto[x]<<'\t';

	cout<<endl<<"weights"<<endl;
	for(x=0;x<n;x++)
		cout<<wt[x]<<'\t';

	cout<<endl<<"values"<<endl;
	for(x=0;x<n;x++)
		cout<<value[x]<<'\t';

	float cap;
	float bag=0;
	cout<<"enter the capacity of the bag"<<endl;
		cin>>cap;

		x=0;
	while(cap-wt[x]>0)
	{
		bag+=value[x];
		cap-=wt[x];
		x++;
	}
	bag+=(cap/wt[x])*value[x];

	cout<<"maximum value "<<'\t'<<bag<<endl;
	getch();
}
