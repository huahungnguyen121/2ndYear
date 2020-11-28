#include "Header.h"

int main() {
	//initialize a list
	dList* list = createList();

	for (int i = 0; i < 20; i++) {
		dNode* temp = createNode(i);
		addTail(list, temp);
	}
	
	//print in 2 orders to test
	printList(list, true);

	cout << endl;

	printList(list, false);

	cout << endl;

	dNode* temp1 = createNode(-2);
	dNode* temp2 = createNode(-1);

	//add -2 before 5 and -1 after 5
	for (dNode* p = list->head; p; p = p->next) {
		if (p->k == 5) {
			addAfter(p, temp1);
			addBefore(p, temp2);
		}
	}
	
	//print in 2 orders to test
	printList(list, true);

	cout << endl;

	printList(list, false);

	cout << endl;

	//remove 1 node at head and 1 node at tail
	removeHead(list);
	removeTail(list);

	//print in 2 orders to test
	printList(list, true);

	cout << endl;

	printList(list, false);

	cout << endl;

	//free memory
	freeList(list);

	return 0;
}