#include<stdio.h>
#include<iostream>

struct Node 
{
	int data;
	Node* next;

	public:

		Node(int d) {
			data = d;
			next = NULL;
		}
};

typedef Node *pNode;

void reverseIteratively(Node*& head) {
	if (!head) return;
	Node* prev = NULL;
	Node* curr = head;

	while (curr) 
	{
		Node* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
  head = prev;
}

void reverseRecursively(Node*& p) {

	if (!p) 
		return;

	Node* rest = p->next;
	  
	if (!rest) 
		return;
	  
	reverseRecursively(rest);
	p->next->next = p;
	p->next = NULL;
	p = rest;
}

int main(int argc, char* argv[]) 
{
	Node a(0);Node b(1);Node c(2);Node d(3);

	a.next = &b;b.next = &c;c.next = &d;

	pNode p = &a;

	/*
	while(p!=NULL) 
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	*/

	reverseIteratively(p);
	//reverseRecursively(p);

	while(p!=NULL) 
	{
		printf("%d\n",p->data);
		p=p->next;
	}

	return 0;
}
