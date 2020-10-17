#include<iostream>
#include<cstring>
using namespace std;
class string
{
    char s1[100];
public:
    string()
    {
        strcpy(s1,"");
    }
    void input()
    {
        cin>>s1;
    }
    void operator +(char s2[])
    {
        strcat(s1,s2);
    }
    void operator ==(char s2[])
    {
        if(strcmp(s1,s2)==0)
        {
            cout<<"string is equal.";
        }
        else
        {
            cout<<"string is not eqyal.";
        }
    }
    void op()
    {
        cout<<s1;
    }
};
int main()
{
    string a1,a2;
    a1.input();
    a2.input();
    a1==a2
    a1+a2;
    a1.op();


}
