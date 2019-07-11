#include<iostream>
using namespace std;

class node {
public:
int f;
int r;
int s[100];
void insert1(int ele);
void del1();
void display();
node(){
    f = -1;
    r = -1;
}
};

void node::insert1(int ele){
    if(r == -1 && f==-1)
    {
        r=0;
        f=0;
        s[r]=ele;
        cout<<"ele inserted"<<"\n";
    }
    else if(r == 99)
    {
        cout<<"queue is full"<<"\n";
    }
    else
    {
        r = r + 1;
        s[r] = ele;
        cout<<"ele inserted"<<"\n";
    }
}

void node::del1(){
    if((f > r))
    {
    cout<<"queue is empty"<<"\n";
    }
    else{
    f = f +1;
    cout<<"ele deleted"<<"\n";
    }
}

void node::display(){
for(int i=f;i<=r;i++)
{
    cout<<s[i]<<"\n";
}
}




int main(){
node b;
b.insert1(10);
b.del1();
b.insert1(20);
b.del1();
b.del1();
b.insert1(40);
b.insert1(50);
b.del1();
b.insert1(66);
b.display();
}
