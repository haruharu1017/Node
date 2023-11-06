// Node implementation starter file for CSCI 60 Homework 9; due Sunday 3/12/23
// List any collaborators and write your name here
//Mengxi He

#include "node.h"

// overloaded << to print entire list
ostream& operator <<(ostream& out, const node * head) {
  if (head==nullptr) return out;
  return out << head->data() << " " << head->link();
}

// inserts a node with specified value at the head (beginning/front) of a list
void list_insert_head(node*& head, node*& tail, int val) {
  head = new node(val,head);
  if (tail==nullptr) tail = head;
}

// inserts a node with specified value at the tail (end/back) of a list
void list_insert_tail(node*& head, node*& tail, int val) {
  node *temp = new node(val,nullptr);
  if (tail==nullptr) {
    head = tail = temp;
  } else {
    tail->set_link(temp);
    tail = tail->link();
  }
}

// iterates through list, keeping track of and then returning # nodes
size_t list_size(const node* head) {
  if (head==nullptr) return 0;
  return 1+list_size(head->link());
}

// iterates through list and returns true if given val is found, false otherwise
bool list_search(const node* head, int val) {
  if (head==nullptr) return false;
  if (head->data()==val) return true;
  return list_search(head->link(),val);
}

// TODO: implement list_insert_sorted
void list_insert_sorted(node*& head, node*& tail, int val)
{
  node* newnode = new node(val, nullptr);
  if(head==nullptr) head=tail=newnode;
  else if(val>=tail->data()){ 
    list_insert_tail(head,tail, val);
    } else if(val<=head->data()){
      list_insert_head(head, tail, val);
    }
  else{
    for(node* curr=head; curr!=nullptr; curr=curr->link())
    {
      if(val>=curr->data()){
        newnode->set_link(curr->link());
        curr->set_link(newnode);
      }
    }
  }
}
