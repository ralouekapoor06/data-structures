#include<iostream>
using namespace std;

class node {
public:
int top;
int s[100];
void push(int ele);
void pop();
void display();
node(){
    top = -1;
}
};

void node::push(int ele){
if(top == 99)
{
cout<<"stack overflow"<<"\n";
}
else{
top = top+1;
s[top] = ele;
}
}

void node::pop(){
if(top == -1)
{
cout<<"stack underflow"<<"\n";
}
else
{
top = top - 1;
cout<<"ele popped"<<"\n";
}


}

void node::display(){
for(int i=0;i<top+1;i++)
{
    cout<<s[i]<<"\n";
}

}


int main(){
node b;
b.push(100);
b.pop();
b.push(200);
b.push(500);
b.pop();
b.push(600);
b.display();
}



