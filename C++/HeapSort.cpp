#include <bits/stdc++.h>
using namespace std;

void create_heap(int n, int* k)
{
    int i, j, key, temp;
    for(int q = 1; q < n; q++)
    {
        i = q;
        key = k[i];
        j = floor(i/2);
        while(i > 0  &&  key > k[j])
        {
            temp = k[i];
            k[i] = k[j];
            k[j] = temp;
            i = j;
            j = i/2;
            if(j < 0)
                j = 0;
            k[i] = key;
        }
    }
}

void heapsort(int n, int* k)
{
    int i, j, key, temp;
    for(int q = n-1; q >= 0; q--)
    {
        temp = k[0];
        k[0] = k[q];
        k[q] = temp;
        i = 0;
        j = 1;
        key = k[i];
        if(j+1 < q)
            if(k[j+1] > k[j])
                j++;
        while(j < q  &&  k[j] > key)
        {
            temp = k[i];
            k[i] = k[j];
            k[j] = temp;
            i = j;
            j = 2*i;
            if(j+1 < q)
            {
                if(k[j+1] > k[j])
                    j++;
                else if(j > n)
                    j = n;
            }
            k[i] = key;
        }
    }
}

int main() {
    int n, num;
    cin >> n;
    if(n < 1 || n > 10000)
    {
        printf("Size of array must be within [1,10000]");
        exit(0);
    }
    int k[n];
    for(int i=0;i<n;i++)
    {
        cin >> num;
        if(num < 1 || num > 10000)
        {
            printf("Number must be within [1,1000000]");
            exit(0);
        }
        k[i] = num;
    }
    create_heap(n,k);
    heapsort(n,k);
    for(int i=0;i<n;i++)
        cout << k[i] << " ";
    return 0;
}
