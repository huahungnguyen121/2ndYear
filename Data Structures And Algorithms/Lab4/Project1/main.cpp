#include "Header.h"

int main() {

	Node* p = createNode(4);

	Node** pointer = new Node * [6];

	p->pLeft = createNode(2);

	p->pRight = createNode(7);

	p->pLeft->pLeft = createNode(1);

	p->pLeft->pRight = createNode(3);

	p->pRight->pLeft = createNode(5);

	pointer[0] = p;
	pointer[1] = p->pLeft;
	pointer[2] = p->pRight;
	pointer[3] = p->pLeft->pLeft;
	pointer[4] = p->pLeft->pRight;
	pointer[5] = p->pRight->pLeft;

	//pre-order traversal
	NLR(p);
	cout << endl;

	//in-order traversal
	LNR(p);
	cout << endl;

	//post-order traversal
	LRN(p);
	cout << endl;

	//level-order traversal
	LevelOrder(p);
	cout << endl;

	cout << Search(p, 5) << endl;

	//count leaf

	cout << countLeaf(p) << endl;

	for (size_t i = 0; i < 5; i++)
		delete pointer[i];

	delete[] pointer;

	return 0;
}