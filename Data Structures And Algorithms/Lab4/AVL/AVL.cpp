#include "AVL.h"

Node* createNode(int data) {
    Node* result = new Node;
    result->key = data;
    result->pLeft = NULL;
    result->pRight = NULL;
    result->height = 0;
    return result;
}

void Insert(Node* &pRoot, int x) {
    if (!pRoot) {
        pRoot = createNode(x);
    }
    else {
        if (pRoot->key < x) {
            Insert(pRoot->pRight, x);
            pRoot->height = getHeight(pRoot);
        }
        else {
            if (pRoot->key > x) {
                Insert(pRoot->pLeft, x);
                pRoot->height = getHeight(pRoot);
            }
            else {
                cout << x <<" existed";
                return;
            }
        }
    }
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