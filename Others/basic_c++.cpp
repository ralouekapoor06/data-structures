#include <iostream>
using namespace std;

class node {
public:
int c;
int d;
void add(int ,int );
node(){
    c = 2;
}
};

void node::add(int a,int b)
{
int z = a + b;
cout<<z;
}


int main()
{
node t;
t.add(10,2);
};



