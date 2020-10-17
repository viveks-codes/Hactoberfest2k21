#include<iostream>
using namespace std;
class complax
{
    int a,b;
public:
    complax()
    {
        a=0;
        b=0;
    }
    void in()
    {
        cin>>a>>b;
    }
    void operator +=(complax c)
    {
        a=a+c.a;
        b=a+c.a;
    }
    void op()
    {
        cout<<a<<" + i"<<b;
    }
};
int main()
{
    complax a1,a2;
    a1.in();
    a2.in();
    cout<<"a1 = ";
    a1.op();
    cout<<"\n";
    cout<<"a2 = ";
    a2.op();
    a1 += a2;
    cout<<"\n";
    cout<<"total = ";
    a1.op();
}
