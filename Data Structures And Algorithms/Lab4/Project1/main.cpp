#include "Header.h"

int main() {

	Node* p = createNode(0);

	Node** pointer = new Node * [6];

	p->pLeft = createNode(1);

	p->pRight = createNode(2);

	p->pLeft->pLeft = createNode(3);

	p->pLeft->pRight = createNode(4);

	p->pRight->pLeft = createNode(5);

	pointer[0] = p;
	pointer[1] = p->pLeft;
	pointer[2] = p->pRight;
	pointer[3] = p->pLeft->pLeft;
	pointer[4] = p->pLeft->pRight;
	pointer[5] = p->pRight->pLeft;

	NLR(p);
	
	cout << endl;

	LNR(p);

	cout << endl;

	LRN(p);
	cout << endl;

	cout << getHeight(p);

	for (size_t i = 0; i < 5; i++)
		delete pointer[i];

	delete[] pointer;

	return 0;
}