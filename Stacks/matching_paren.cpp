#include<iostream>
#include<string.h>
using namespace std;

class node {
public:
void check(char exp[100]);
void push(char ele);
char pop();
void exit1();
int top;
int s[100];
node(){
top = -1;
}
};

void node::check(char exp[])
{
char t;
for(int i=0;i<=strlen(exp);i++)
{
    if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
    {
        push(exp[i]);
    }
    else if(exp[i] == ')')
    {
        t = pop();
        if(t != '(')
        {
        cout<<"not match"<<"\n";
        return;
        }
    }
    else if(exp[i] == '}')
    {
        t = pop();
        if(t != '{')
        {
        cout<<"not match"<<"\n";
        return;
        }
    }
    else if(exp[i] == ']')
    {
        t = pop();
        if(t != '[')
        {
        cout<<"not match"<<"\n";
        return;
        }
    }
}
if(top == -1)
{
cout<<"correct match";
}
else{
cout<<"not matched";
}
}

void node::push(char ele)
{
    if(top == 99)
    {
    cout<<"stack overfull";
    exit1();
    }
    top = top + 1;
    s[top] = ele;
    cout<<"ele pushed";
}

char node::pop()
{
    if(top == -1)
    {
    cout<<"stack empty";
    exit1();
    }
    cout<<"ele popped";
    return s[top--];
}

void node::exit1()
{
cout<<"terminated";
}


int main()
{
node b;
char exp[100];
cout<<"enter the expression";
cin>>exp;
b.check(exp);
}
