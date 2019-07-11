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


