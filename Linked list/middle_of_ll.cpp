#include<iostream>
using namespace std;

class node{
public:
node* insert1(int,node *start);
node* mid(node *start);
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

node* node::mid(node *start){
    if(start == NULL)
    {
        cout<<"ll is empty";
        return start;
    }
    node *fast = start;
    node *slow = start;
    while(fast->next !=NULL)
    {
        fast = fast->next;
        if(fast->next == NULL)
        {
            cout<<" The middle ele is "<<slow->data<<" ";
            slow = slow->next;
            cout<<slow->data;
            return start;
        }
        fast = fast->next;
        slow = slow->next;
    }
    cout<<" The middle ele is "<<slow->data;
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
start=b.insert1(40,start);
b.disp1(start);
start=b.mid(start);
}

