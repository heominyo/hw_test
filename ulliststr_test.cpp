/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
#include "ulliststr.cpp"

using namespace std;

void printList(const ULListStr* data){
	if(data->empty()){
		cout << "Data is empty!!!" << endl;
		return;
	}
	for(size_t i = 0;i<data->size();i++){
		cout << data->get(i) << " ";
	}
	cout << endl;
}

int main(int argc, char* argv[])
{
	ULListStr* list = new ULListStr();
	string arr[20] = {
		"hi", "bye", "said", "jog", "building",
		"guy", "sad", "but", "ice", "cream",
		"is", "good", "so", "job", "made",
		"hapy", "by", "dessert", "yay", "end"
	};
	for(int i = 0;i<20;i++){
		list->push_front(arr[i]);
		list->push_back(arr[i]);
	}
	printList(list);
	cout << list->size() << endl;
  return 0;
}
