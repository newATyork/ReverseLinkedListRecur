#include<iostream>
//#include <stdio.h>
//#include <stdlib.h>

struct Node { // nodes of linked list
   int data;
   Node* next;
   Node(int d, Node* n) : data(d), next(n) {}
   ~Node() {delete next;}
};
//
void printList(Node* p) { // print linked list
	while (p!=NULL) {
		std::cout << p->data;
		p = p->next;
		if (p!=NULL) std::cout << ",";
	}
	 std::cout << std::endl;
}
//
Node* reverseList(Node* p) { // recursively reverse linked list
	if (p==NULL) return NULL; // end of list - recursion terminates
	Node* n = p->next; // keep pointer to next node
	p->next = NULL; // detach this node from list
	Node* r = reverseList(n); // recursive call
	if (r==NULL) return p; // last node becomes first node in reversed list
	n->next = p; // reverse node order - next node is now followed by this node
	return r; // always return first node 
}
//
void test() {
	// setup linked list with five nodes
	Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5,NULL))))); 
	printList(head); // print
	head = reverseList(head); // reverse
	printList(head); // print
	delete head; // deallocate nodes
}

int main(int argc, char** argv) {
	test();
	return 0;
}