#include<iostream>
using namespace std;

class node{
public:
node* insert1(int,node *start);
node* sortt(node *start);
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

void node::disp1(node *start){
    while(start->next != NULL)
    {
        cout<<start->data<<"->";
        start = start->next;
    }
    cout<<start->data;
}

node* node::sortt(node *start){
    if(start == NULL)
    {
        cout<<"ll is empty";
        return start;
    }
    int small;
    node *p = start;
    node *q;
    int temp;
    while(p !=NULL)
    {
        q = p->next;
        while(q !=NULL)
        {
            if(p->data > q->data)
            {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p=p->next;
    }
    return start;
}


int main(){
node b;
node *start=NULL;
start=b.insert1(10,start);
start=b.insert1(30,start);
start=b.insert1(20,start);
start=b.insert1(100,start);
start=b.insert1(5,start);
b.disp1(start);
cout<<endl;
start=b.sortt(start);
b.disp1(start);
}
