#include <bits/stdc++.h>
using namespace std;

void merge(int* k, int low, int middle, int high)
{
    int i, j, l; 
    int n1 = middle - low + 1; 
    int n2 = high - middle; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = k[low + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = k[middle + 1 + j]; 
    i = 0; 
    j = 0; 
    l = low; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            k[l] = L[i]; 
            i++; 
        } 
        else { 
            k[l] = R[j]; 
            j++; 
        } 
        l++; 
    } 
    while (i < n1) { 
        k[l] = L[i]; 
        i++; 
        l++; 
    } 
    while (j < n2) { 
        k[l] = R[j]; 
        j++; 
        l++; 
    } 
}

void mergesort(int* k, int low, int high)
{
    if (low < high) 
    { 
        int middle = low + ((high - low + 1) / 2) - 1; 
        mergesort(k, low, middle); 
        mergesort(k, middle + 1, high); 
        merge(k, low, middle, high); 
    } 
}

int main() {
    int n, num;
    cin >> n;
    if(n < 1 || n > 10000)
    {
        cout << "Size of array must be within [1,10000]" << endl;
        exit(0);
    }
    int k[n];
    for(int i=0;i<n;i++)
    {
        cin >> num;
        if(num < 1 || num > 10000)
        {
            cout << "Number must be within [1,1000000]" << endl;
            exit(0);
        }
        k[i] = num;
    }
    mergesort(k, 0, n-1);
    for(int i=0;i<n;i++)
        cout << k[i] << " ";
    return 0;
}
