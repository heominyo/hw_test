/*
CSCI 104: Homework 2 Problem 6

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
	//base case
	if(in == NULL) return;
	//create temp Node
	int v = in->value;
	Node* toAdd = new Node(v, NULL);
	if(v%2 == 0) {
		//if the value is even, make the next toAdd and recurse to the nexteven
		evens = toAdd;
		split(in->next, odds, evens->next);
	}
	else {
		//if the value is odd, make the next toAdd and recurse to the next odd
		odds = toAdd;
		split(in->next, odds->next, evens);
	}
}

/* If you needed a helper function, write it here */
