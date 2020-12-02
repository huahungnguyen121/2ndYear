#include "Header.h"

Node* createNode(int data)
{
	Node* temp = new Node;
	temp->key = data;
	temp->pLeft = NULL;
	temp->pRight = NULL;
	return temp;
}

int getHeight(Node* pRoot)
{
	if (pRoot) {
		int left = getHeight(pRoot->pLeft);
		int right = getHeight(pRoot->pRight);

		if (left > right)
			return 1 + left;
		else return 1 + right;
	}
	else return 0;
}

void NLR(Node* pRoot)
{
	if (pRoot) {
		cout << pRoot->key << " ";
		NLR(pRoot->pLeft);
		NLR(pRoot->pRight);
	}
}

void LNR(Node* pRoot)
{
	if (pRoot) {
		LNR(pRoot->pLeft);
		cout << pRoot->key << " ";
		LNR(pRoot->pRight);
	}
}

void LRN(Node* pRoot)
{
	if (pRoot) {
		LRN(pRoot->pLeft);
		LRN(pRoot->pRight);
		cout << pRoot->key << " ";
	}
}

void printLevel(Node* pRoot, int level) {
	if (pRoot && level == 0)
		cout << pRoot->key << " ";
	else if (pRoot && level > 0) {
		printLevel(pRoot->pLeft, level - 1);
		printLevel(pRoot->pLeft, level - 1);
	}
}

void LevelOrder(Node* pRoot)
{
	
}
