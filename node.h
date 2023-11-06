// Node interface file for CSCI 60 Homework 9; due Sunday 3/12/23

#ifndef NODE_H
#define NODE_H
#include <iostream>
using std::ostream;

class node {
public:
  // creates a new node with given data and link values
  node(int data, node* link) : data_(data), link_(link) {}
  node() : node(0,nullptr) {}

  // const accessors
  int data() const { return data_; }
  node * link() const { return link_; }

  // mutators
  void set_data(int newdata) { data_ = newdata; }
  void set_link(node* newlink) { link_ = newlink; }

private:
  int data_;
  node * link_;
  // INVARIANTS: data_ is the node value and link_ points to next node
};

ostream& operator <<(ostream& out, const node * head);

// non-member functions for additional list functionality
void list_insert_head(node*& head, node*& tail, int val);
void list_insert_tail(node*& head, node*& tail, int val);
std::size_t list_size(const node* head);
bool list_search(const node* head, int val);

// new function for you to implement in node.cpp for HW9
void list_insert_sorted(node*& head, node*& tail, int val);

#endif // NODE_H
