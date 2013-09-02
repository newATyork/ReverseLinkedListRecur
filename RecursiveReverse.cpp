#include<stdio.h>
#include<iostream>

struct node 
{
	int data;
	struct node* next;

	public:

		node(int d) {
			data = d;
			next = NULL;
		}
};

typedef node *pNode,**ppNode;


void RecursiveReverse(struct node** headRef) 
{
	struct node* first;
	struct node* rest;
	
	if (*headRef == NULL) return;               // empty list base case
	
	first = *headRef;                           // suppose first = {1, 2, 3}
	rest = first->next;                          // rest = {2, 3}
	
	if (rest == NULL) return;                   // empty rest base case
	RecursiveReverse(&rest);                    // Recursively reverse the smaller {2, 3} case
	
	                                            // after: rest = {3, 2}
	first->next->next = first;                  // put the first elem on the end of the list
	first->next = NULL;                         // (tricky step -- make a drawing)
	*headRef = rest;                            // fix the head pointer
}

/*
Here, the function’s parameter list “void RecursiveReverse(struct node** headRef)” 
and the function call “RecursiveReverse(&rest)” implies the pointer “rest” 
would be changed itself through the call.

Suddenly, everything is clear. Looking back, my initial confuse is due to my unfamilarity with C++ 
(I was working in embedded area, using C). Although you have defined the recursive function 
as “void reverse(Node* & p)” and emphasized this reference is necessary 
when changes to the input parameter is intended to propagate back to its caller, 
I simply forgot this fact in going through your recursive solution. 

In reading your call of “reverse(rest)”, I didn’t realized that a reference has been passed in 
and “rest” would be modified. What an ignorance!
*/

int main(int argc, char* argv[]) 
{
	node a(0);node b(1);node c(2);node d(3);

	a.next = &b;
	b.next = &c;
	c.next = &d;

	pNode pToOneLevel = &a;

	ppNode p = &pToOneLevel;

	RecursiveReverse(p);

	while( pToOneLevel != NULL ) 
	{
		printf("%d\n",pToOneLevel->data);
		pToOneLevel = pToOneLevel->next;
	}

	return 0;
}