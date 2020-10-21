#include <bits/stdc++.h>
using namespace std;

typedef struct lst
{
    int coeff, powerX, powerY;
    struct lst* next;
}node;

node *result = NULL;
int result_count = 0;

void insert_node(node** p,int coeff,int x, int y)
{
    node* new1 = (node*)malloc(sizeof(node));
    new1->coeff = coeff;
    new1->powerX = x;
    new1->powerY = y;
    if(*p == NULL || x>((*p)->powerX) || (x==((*p)->powerX) && y>((*p)->powerY)))
    {
        new1->next = *p;
        *p = new1;
    }
    else
    {
        node* ptr = *p;
        while(ptr->next!=NULL)
        {
            if(x>(ptr->next->powerX) || (x==ptr->next->powerX && y>(ptr->next->powerY)))
                break;
            ptr = ptr->next;
        }
        new1->next = ptr->next;
        ptr->next = new1;
    }
}

void copy(node *p)
{
    node* ptr = result;
    while(ptr->next !=NULL)
        ptr = ptr->next;
    ptr->next = p;
}

void calculate_result(node *p1, node *p2,int m,int n)
{
    while(p1!=NULL && p2!=NULL)
    {
        int c1=p1->coeff, c2=p2->coeff, x1=p1->powerX, x2=p2->powerX, y1=p1->powerY, y2=p2->powerY;
        if(x1==x2 && y1==y2)
        {
            insert_node(&result, c1+c2, x1, y1);
            p1 = p1->next;
            p2 = p2->next;
            result_count++;
            m--;
            n--;
        }
        else if(x1>x2 || (x1==x2 && y1>y2))
        {
            insert_node(&result, c1, x1, y1);
            p1 = p1->next;
            result_count++;
            m--;
        }
        else
        {
            insert_node(&result, c2, x2, y2);
            p2 = p2->next;
            result_count++;
            n--;
        }
    }
    result_count += m + n;
    if(result_count > 10)
    {
        cout << "Number of terms exceed the MAXSIZE limit\n" << endl;
        exit(0);
    }
    if(p1!=NULL)
    {
        copy(p1);
    }
    else if(p2!=NULL)
    {
        copy(p2);
    }
}

int main() {
    int m,n,coeff,powerX,powerY;
    scanf("%d%d",&m,&n);
    if(m>10 || n>10)
    {
        cout << "Number of terms exceed the MAXSIZE limit\n" << endl;
        exit(0);
    }
    node* p1 = NULL;
    node* p2 = NULL;
    for(int i=0;i<m;i++)
    {
        cin >> coeff >> powerX >> powerY;
        if(coeff==0)
        {
            m--;
            continue;
        }
        insert_node(&p1,coeff,powerX,powerY);
    }
    for(int i=0;i<n;i++)
    {
         cin >> coeff >> powerX >> powerY;
        if(coeff==0)
        {
            n--;
            continue;
        }
        insert_node(&p2,coeff,powerX,powerY);
    }
    calculate_result(p1, p2, m, n);
    cout << result_count << endl;
    while(result_count--)
    {
        cout << result->coeff << " " << result->powerX << " " << result->powerY << endl;
        result = result->next;
    }
    return 0;
}
