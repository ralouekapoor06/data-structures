#include<iostream>
#include<string.h>
using namespace std;

class node{
public:
node* insert1(int,node *root);
node* inorderiter(node *root);
node* preorderiter(node *root);
node* pop();
void push(node *a1);
node *left;
node *right;
int data;
node *s[100];
int top;
node(){
    top = -1;
}
};


node* node::insert1(int a,node *root)
{
    char dir[10];
    if(root == NULL)
    {
        node *temp = new node();
        temp->data = a;
        temp->left = NULL;
        temp->right =NULL;
        root = temp;
        cout<<"root is made of "<<a<<endl;
        return root;
    }
    node *temp = new node();
    temp->left = NULL;
    temp->right = NULL;
    temp->data = a;
    node *cur=root;
    node *prev=NULL;
    cout<<"enter the direction for insertion"<<endl;
    cin >> dir;
    int i;
    for(i=0;i<strlen(dir);i++)
    {
        if(dir[i] == 'L')
        {
            prev = cur;
            cur = prev->left;
        }
        else if(dir[i] == 'R')
        {
            prev = cur;
            cur = prev->right;
        }
        else
        {
            cout<<"inappropriate command"<<endl;
            return root;
        }
        if(cur == NULL)
        {
            break;
        }
    }

    if(i != (strlen(dir)-1) || cur !=NULL)
    {
        cout<<"cannot insert"<<endl;
        return root;
    }


    if(dir[i]=='L')
    {
        prev->left = temp;
    }
    else
    {
        prev->right = temp;
    }
    cout<<"element is inserted "<<a<<endl;
    return root;
}


node* node::inorderiter(node *root){
    if(root == NULL)
    {
        cout<<"empty as of now"<<endl;
        return root;
    }
    node *n =root;
    while(top!=-1 || n!=NULL)
    {
        if(n!=NULL)
        {
            push(n);
            n=n->left;
        }
        else
        {
        n = pop();
        cout<<n->data;
        n = n->right;
        }
    }
    return root;
}

node* node::preorderiter(node *root){
    if(root == NULL)
    {
        cout<<"empty as of now"<<endl;
        return root;
    }
    node *n =root;
    while(top!=-1 || n!=NULL)
    {
        if(n!=NULL)
        {
            cout<<n->data;
            push(n);
            n=n->left;
        }
        else
        {
        n = pop();
        n = n->right;
        }
    }
    return root;
}

void node::push(node *a1){
    if(top==99){
        cout<<"cannot insert"<<endl;
    }
    top = top+1;
    s[top]=a1;
}

node* node::pop(){
    if(top == -1)
    {
        cout<<"stacks empty"<<endl;
        return NULL;
    }
    return s[top--];
}






int main(){
node b;
node *root = NULL;
root=b.insert1(1,root);
root=b.insert1(2,root);
root=b.insert1(3,root);
root=b.insert1(4,root);
root=b.insert1(5,root);
root=b.inorderiter(root);
root=b.preorderiter(root);
}
