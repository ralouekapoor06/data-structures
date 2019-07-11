#include<iostream>
using namespace std;

class node{
public:
node* insert1(int,node *start);
void disp1(node *start);
node* del_from_start(node * start);
node* del_from_end(node * start);
node *next;
int data;
};

node* node::insert1(int a,node *start){
    if(start == NULL)
    {
        node *temp = new node();
        temp->next = temp;
        temp->data = a;
        start = temp;
        return start;
    }
    node *temp = new node();
    temp->next = start;
    temp->data = a;
    node *iter = start;
    while(iter->next !=start)
    {
        iter = iter->next;
    }
    iter->next = temp;
    return start;
}

node* node::del_from_start(node *start){
    if(start==NULL){
        cout<<"ll is empty";
        return start;
    }
    if(start->next == start){
        delete start;
        return NULL;
    }
    //avoid dangling pointer conditions
    node *y = start;
    while(y->next !=start)
    {
        y = y->next;
    }
    node *x = start;
    node *g = start;
    x = x->next;
    y->next = x;
    start = x;
    delete g;
    return start;
}

node* node::del_from_end(node *start){
    if(start==NULL){
        cout<<"ll is empty";
        return start;
    }
    if(start->next == NULL){
        delete start;
        return NULL;
    }
    //avoid dangling pointer conditions
    node *y = start;
    while((y->next)->next !=start){
        y=y->next;
    }
    node *x = y->next;
    delete(x);
    y->next = start;
    return start;
}

void node::disp1(node *start){
    node *y1 = start;
    while(y1->next != start)
    {
        cout<<y1->data<<"->";
        y1 = y1->next;
    }
    cout<<y1->data;
}

int main(){
node b;
node *start=NULL;
start=b.insert1(10,start);
start=b.insert1(20,start);
start=b.insert1(30,start);
start=b.del_from_start(start);
b.disp1(start);
}
