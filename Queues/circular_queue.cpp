#include<iostream>
using namespace std;

class node {
public:
int r;
int q;
int s[3];
void insert1(int ele);
void del1();
void display();
node(){
    q = -1;
    r = -1;
}
};

void node::insert1(int ele){
if(r == -1 && q==-1)
{
    r=0;
    q=0;
    s[r] = ele;
    cout<<"inserted";
}
else if(r==2 && q!=0){
    r = 0;
    s[r] = ele;
    cout<<"inserted"<<endl;
}
else if(r == 2 && q==0)
{
    cout<<"queue is full"<<"\n";
}
else if((r == q -1) && (s[2] != '#'))
{
    cout<<"queue is full"<<"\n";
}
else{
r=r+1;
s[r] = ele;
cout<<"inserted"<<"\n";
}
}

void node::del1(){
if(q == -1){
    r = -1;
    cout<<"queue is empty"<<"\n";
}
else if(q == r + 1)
{
    for(int i=0;i<=2;i++)
    {
        if(s[i] == '#')
        {
            cout<<"queue is empty"<<endl;
            q = -1;
            r = -1;
        }
    }
}
else if(q==2 && r == 2)
{
    s[2]= '#';
    q = -1;
    r = -1;
    cout<<"queue is empty"<<"\n";
}
else if(q==2 && r>=0)
{
    s[2] = '#';
    q=0;
}
else{
s[q] = '#';
q=q+1;
cout<<"ele deleted"<<"\n";
}
}

void node::display(){
if(q==-1)
{
    cout<<"empty"<<endl;
    return;
}
else if(q<=r){
for(int i=q;i<=r;i++)
{
    cout<<s[i]<<endl;
}
}
else
{
for(int i=q;i<=2;i++)
{
    cout<<s[i]<<endl;
}
for(int i=0;i<=r;i++)
{
    cout<<s[i]<<endl;
}
}
}




int main(){
node b;
for(int i=0;i<=2;i++)
{
    b.s[i] = '#';
}
b.insert1(10);
b.del1();
b.insert1(20);
b.insert1(40);
b.display();
}
