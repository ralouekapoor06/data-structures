#include<iostream>
#include<string.h>
using namespace std;

class node{
public:
node* insert1(int,node *root);
node *left;
node *right;
int data;
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



int main(){
node b;
node *root = NULL;
root=b.insert1(10,root);
root=b.insert1(20,root);
root=b.insert1(40,root);
}
