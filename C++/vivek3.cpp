#include<iostream>
using namespace std;
int main()
{
    int n,i,z=1;
    string a[1000],b[1000];
    cout<<"enter n : ";
    cin>>n;
    cout<<"enter element of set : ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        z=z*2;
    }

    cout<<"power set of given set : {";
    for(i=0;i<z;i++)
    {
        cout<<"{";
        for(int j=0;j<n;j++)
        {
            if(i & (1 << j))
            {
                cout<<a[j];
            }
        }
        cout<<"}";
        if(i!=z-1)
        {
            cout<<",";
        }
    }
    cout<<"}";
    cout<<"}";
    cout<<"}";
}
