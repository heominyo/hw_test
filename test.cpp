#include "split.h"
#include "split.cpp"
#include <iostream>

using namespace std;

void add(Node*& list, int val){
	Node * toAdd = new Node(val, NULL);
	if(list == NULL) {
		list = toAdd;
		return;
	}
	Node * temp = list;
	while(temp->next != NULL) temp = temp->next;
	temp->next = toAdd;
}

void print(const Node* list){
	if(list == NULL) cout << endl;
	else if(list->next == NULL) {
		cout << list->value << "]";
		print(list->next);
	}
	else{
		cout << list->value << ", ";
		print(list->next);
	}
}

int main(){
	Node* list = NULL;
	for(int i = 0;i<100;i++){
		add(list, i * 3);
	}	
	cout << "[";
	print(list);
	Node* odds = NULL;
	Node* evens = NULL;
	split(list, odds, evens);
	cout << "[";
	print(odds);
	cout << "[";
	print(evens);
	
	return 0;
}
