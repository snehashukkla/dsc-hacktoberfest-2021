/*
    @author : Kapil Bhale
    
    Assign value of next node to current node and then delete next node.
*/

#include <bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node* next;
};

node* create(int data){
  node* tmp = new node();
  tmp->data = data;
  tmp->next = NULL;
  return tmp;
}

void deletedNode(node *del) {
       // Your code here
       cout << del->data << endl;
       del->data = del->next->data;
       del->next = del->next->next;
}


int main(){
  // create a linked list
  node* head = new node();
  head = create(2);
  head->next = create(3);
  node* toBeDeleted = create(4);
  head->next->next = toBeDeleted;
  head->next->next->next = create(5);
  head->next->next->next->next = create(6);
  head->next->next->next->next->next = create(7);

  deletedNode(toBeDeleted);
  return 0;
}