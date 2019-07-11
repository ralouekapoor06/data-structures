#include<iostream>
using namespace std;

class node{
public:
node* insert1(int,node *start);
void disp1(node *start);
node* del_from_start(node * start);
node* del_from_end(node * start);
node *next;
node *prev;
int data;
};

node* node::insert1(int a,node *start){
    if(start == NULL)
    {
        node *temp = new node();
        temp->next = NULL;
        temp->prev = NULL;
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
    temp->prev = iter;
    return start;
}

node* node::del_from_start(node *start){
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
    start=start->next;
    delete y;
    start->prev = NULL;
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
    while((y->next)->next !=NULL){
        y=y->next;
    }
    node *x = y->next;
    delete(x);
    y->next = NULL;
    return start;
}


void node::disp1(node *start){
    while(start->next != NULL)
    {
        cout<<start->data<<"<->";
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
start = b.del_from_end(start);
b.disp1(start);
}
