#include <iostream>
using namespace std;

void swap1(char& x,char& y)
{
    char temp;
    temp=x;
    x=y;
    y=temp;
}


void permutations(string s1, int i, int n)
{
    if (i == n)
    {
        cout << s1 << "\n";
    }

    for (int j = i; j <= n; j++)
    {

        swap1(s1[i], s1[j]);

        permutations(s1, i + 1, n);

        swap1(s1[i], s1[j]);
    }
}

int main()
{
    string s1;
    cout<<"enter a string for permutation set : \n";
    cin>>s1;
    cout<<"\no/p ---------------------- : \n\n";
    int x= s1.size();

    permutations(s1, 0, x - 1);

    return 0;
}
