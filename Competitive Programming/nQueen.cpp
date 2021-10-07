#include <bits/stdc++.h>
#define INF 9999
using namespace std;

// to check wether the given queen (having number queen) can be placed in column
bool isSafe(int *Q, int queen, int column)
{
    for (int i = 0; i <= queen - 1; i++)
    {
        if (column == Q[i] || (queen - i) == std::abs(Q[i] - column))
            return false;
    }
    return true;
}
 
bool nQueen(int *Q, int queen, int n)
{
    if (queen == n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(Q, queen, i))
        {
            // place queen in ith column
            Q[queen] = i;

            //recursive call
            if (nQueen(Q, queen + 1, n))
            {
                return true;
            }

            // backtracking
            Q[queen] = INF;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;
    int *Q = new int[n];
    for (int i = 0; i < n; i++)
    {
        Q[i] = INF;
    }
    if (nQueen(Q, 0, n))
    {
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (Q[i] == j)
                    cout << "1 ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "There Is No Valid Arrangement";
    }

    return 0;
}
