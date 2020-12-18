#include "RBT.h"

int main() {
    //initialize nill node
    Node* nill = new Node;
    nill->key = -1;
    nill->color = false;
    nill->pParent = nill;
    nill->pLeft = nill;
    nill->pRight = nill;

    Node* pRoot = nill; //empty tree

	Insert(pRoot, 2, nill);
	Insert(pRoot, 6, nill);
	Insert(pRoot, 7, nill);
	Insert(pRoot, 1, nill);
	Insert(pRoot, 9, nill);

    //release memory
    release(pRoot, nill);
    delete nill;
    
    return 0;
}