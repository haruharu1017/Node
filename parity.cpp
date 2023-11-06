// Parity implementation starter file for CSCI 60 Homework 9; due Sunday 3/12/23
// List any collaborators and write your name here
//Mengxi He

#include "parity.h" // Don't add any additional libraries/namespaces!

// a 0-arg constructor that sets up an empty parity object
Parity::Parity() {
	headE=tailE=headO=tailO=nullptr;
	nE=nO=0;
}

// a copy-constructor that deep-copies the contents of another object
Parity::Parity(const Parity& other) {
	node *curr = other.headE;
	while (curr!=nullptr) {
		list_insert_tail(headE,tailE,curr->data());
		curr = curr->link();
	}
	curr = other.headO;
	while (curr!=nullptr) {
		list_insert_tail(headO,tailO,curr->data());
		curr = curr->link();
	}
	nE = other.nE;
	nO = other.nO;
}

// TODO: implement insert, <<, max, min, destructor, and = below
void Parity::insert(int val)
{
	if(val%2==0)
	{
		list_insert_sorted(headE, tailE, val);
		nE++;
	}
	else{
		list_insert_sorted(headO, tailO, val);
		nO++;
	}
}

int Parity::min() const{
	int minE = INT_MAX;
	for(node* curr=headE; curr!=nullptr; curr=curr->link())
	{
		if(curr->data() < minE)
		minE = curr->data();
	}
	int minO = INT_MAX;
	for(node* curr=headO; curr!=nullptr; curr=curr->link())
	{
		if(curr->data() < minO)
		minO = curr->data();
	}
	if(minE < minO) return minE;
	else return minO;
}

int Parity::max() const{
	int maxE = INT_MIN;
	for(node* curr=headE; curr!=nullptr; curr=curr->link())
	{
		if(curr->data() > maxE)
		maxE = curr->data();
	}
	int maxO = INT_MIN;
	for(node* curr=headO; curr!=nullptr; curr=curr->link())
	{
		if(curr->data() > maxO)
		maxO = curr->data();
	}
	if(maxE > maxO) return maxE;
	else return maxO;
}

Parity::~Parity()
{
	for(node* curr=headE; curr!=nullptr; curr=headE)
	{
		headE = headE->link();
		delete curr;
	}
	tailE = nullptr;
	for(node* curr=headO; curr!=nullptr; curr=headO)
	{
		headO = headO->link();
		delete curr;
	}
	tailO = nullptr;
}

Parity& Parity::operator=(const Parity& rhs)
{
	for(node* curr=headE; curr!=nullptr; curr=headE)
	{
		headE = headE->link();
		delete curr;
	}
	tailE = nullptr;
	for(node* curr=headO; curr!=nullptr; curr=headO)
	{
		headO = headO->link();
		delete curr;
	}
	tailO = nullptr;

	node *curr = rhs.headE;
	while (curr!=nullptr) {
		list_insert_tail(headE,tailE,curr->data());
		curr = curr->link();
	}
	curr = rhs.headO;
	while (curr!=nullptr) {
		list_insert_tail(headO,tailO,curr->data());
		curr = curr->link();
	}
	nE = rhs.nE;
	nO = rhs.nO;

	return *this;
}

ostream& operator <<(ostream& out, const Parity& lists)
{
	out << "Evens: ";
	for(node* curr=lists.headE; curr!=nullptr; curr=curr->link())
	out << curr->data() << " ";
	out << "\nOdds: ";
	for(node* curr=lists.headO; curr!=nullptr; curr=curr->link())
	out<< curr->data()<<" ";
	return out;
}