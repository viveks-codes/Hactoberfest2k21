#include<iostream>
using namespace std;
class shape
{
    protected:
    int length;
    public:
    virtual void read(){}
    virtual void area(){}
};
class square:public shape
{
public:
    void read()
    {
        cout<<"enter the length of square:";
        cin>>length;
    }
    void area()
    {
        cout<<"your area of square is:"<<length*length<<endl;
    }
};
class circle:public shape
{
    void read()
    {
        cout<<"enter the radius of circle:";
        cin>>length;
    }
    void area()
    {
        cout<<"your area of circle is:"<<3.14*length*length<<endl;
    }
};
int main()
{
    shape *ptr[2];
    square s;
    circle c;
    ptr[0]=&s;
    ptr[0]->read();
    ptr[0]->area();
    ptr[1]=&c;
    ptr[1]->read();
    ptr[1]->area();
}
