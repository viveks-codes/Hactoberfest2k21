#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char s[1000000]="(";
char r_polish[1000000]="";
long int top=0,top_r=0,n=0;

int f(char operation)
{
    if(operation=='+' || operation=='-')
        return 1;
    else if(operation=='*' || operation=='/')
        return 3;
    else if(operation=='^')
        return 6;
    else if(operation=='(')
        return 9;
    else if(operation==')')
        return 0;
    else if((operation>=65 && operation<=91) || (operation>=97 && operation<=123))
        return 7;
    printf("INPUT EXPRESSION IS INVALID");
            exit(0);
}

int g(char operation)
{
    if(operation=='+' || operation=='-')
        return 2;
    else if(operation=='*' || operation=='/')
        return 4;
    else if(operation=='^')
        return 5;
    else if(operation=='(')
        return 0;
    return 8;
}

int r(char operation)
{
    if(operation=='+' || operation=='-' || operation=='*' || operation=='/' || operation=='^')
        return -1;
    else if((operation>=65 && operation<=91) || (operation>=97 && operation<=123))
        return 1;
    return 0;
}

int main() {
    char temp,next;
    top++;
    int rank=0;
    next=getchar();
    while(next!=EOF)
    {
        if(next=='(')
            n++;
        else if(next==')')
            n--;
        if(top<0)
        {
            printf("INPUT EXPRESSION IS INVALID");
            exit(0);
        }
        while(f(next)<g(s[top-1]))
        {  
            temp=s[top-1];
            top--;
            s[top]='\0';
            r_polish[top_r]=temp;
            top_r++;
            rank+=r(temp);
            if(rank<1)
            {
                printf("INPUT EXPRESSION IS INVALID");
                exit(0);
            }
        }
        if(f(next)!=g(s[top-1]))
        {
            s[top]=next;
            top++;
        }
        else
        {
            top--;
            s[top]='\0';
        }
        next=getchar();
    }
    next=')';
    while(top>1)
    {
        while(f(next)<g(s[top-1]))
        {
            
            temp=s[top-1];
            top--;
            s[top]='\0';
            r_polish[top_r]=temp;
            top_r++;
            rank+=r(temp);
            if(rank<1)
            {
                printf("INPUT EXPRESSION IS INVALID");
                exit(0);
            }
        }
        if(f(next)!=g(s[top-1]))
        {
            s[top]=next;
            top++;
        }
        else
        {
            top--;
            s[top]='\0';
        }
    }
    if(top<0 || rank<1 || n!=0)
        printf("INPUT EXPRESSION IS INVALID");
    else
    {
        printf("%s",r_polish);
    }
    return 0;
}
