#include<iostream>
using namespace std;

class node{
public:
node* insert1(int,node *start);
node* rev(node *start);
void disp1(node *start);
node *next;
int data;
};

node* node::insert1(int a,node *start){
    if(start == NULL)
    {
        node *temp = new node();
        temp->next = NULL;
        temp->data = a;
        start = temp;
        return start;
    }
    node *temp = new node();
    temp->next = NULL;
    temp->data = a;
    node *iter = start;
    while(iter->next !=NULL)
    {
        iter = iter->next;
    }
    iter->next = temp;
    return start;
}

node* node::rev(node *start){
    if(start == NULL)
    {
        cout<<"ll is empty";
        return start;
    }
    node *p=start;
    node *r = NULL;
    node *q = p->next;
    p->next = r;
    while(q !=NULL)
    {
        r = p;
        p = q;
        q = p->next;
        p->next = r;
    }
    start=p;
    return start;
}

void node::disp1(node *start){
    while(start->next != NULL)
    {
        cout<<start->data<<"->";
        start = start->next;
    }
    cout<<start->data;
}


int main(){
node b;
node *start=NULL;
start=b.insert1(10,start);
start=b.insert1(20,start);
start=b.insert1(30,start);

b.disp1(start);
cout<<endl;
start=b.rev(start);
b.disp1(start);
}
