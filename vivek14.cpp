#include<iostream>
using namespace std;
class time
{
    int hour,minit,sec;
public:
    time()
    {
        hour=0;
        minit=0;
        sec=0;
    }
    void input()
    {
        cin>>hour>>minit>>sec;

    }
    void operator +(time a)
    {

        hour=hour+a.hour;
        minit=minit+a.minit;
        sec=sec+a.sec;
        if(sec>=60)
        {
            minit++;
            sec=sec-60;
        }
        if(minit>=60)
        {
            hour++;
            minit=minit-60;
        }
    }
    void output()
    {
        cout<<hour<<":"<<minit<<":"<<sec;
    }
};
int main()
{
    time a1,a2,a3;
    a1.input();
    a2.input();
    a1+a2;
    a1.output();

}
