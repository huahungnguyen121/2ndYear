#include "RBT.h"

void release(Node*& pRoot, Node* nill) {
    if (pRoot != nill) {
        Node* p1 = pRoot->pLeft;
        Node* p2 = pRoot->pRight;
        delete pRoot;
        release(p1, nill);
        release(p2, nill);
    }
}

Node* createNode(int key, bool color, Node* nill) {
    Node* temp = new Node;
    temp->key = key;
    temp->color = color;
    temp->pLeft = nill;
    temp->pRight = nill;
    temp->pParent = nill;
    return temp;
}

void Insert(Node*& pRoot, int x, Node* nill) {
    Node* p1 = nill;
    Node* p2 = pRoot;

    while (p2 != nill) {
        p1 = p2;
        if (p2->key > x)
            p2 = p2->pLeft;
        else {
            if (p2->key == x)
                return;
            else
                p2 = p2->pRight;
        }
    }

    p2 = createNode(x, true, nill);
    p2->pParent = p1;
    if (p1 == nill)
        pRoot = p2;
    else {
        if (p1->key > x)
            p1->pLeft = p2;
        if (p1->key < x)
            p1->pRight = p2;
    }
}