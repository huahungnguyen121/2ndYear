#ifndef _RBT_H_
#define _RBT_H_

#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* pLeft;
    Node* pRight;
    Node* pParent;
    bool color; //false is black and true is red
};

void release(Node*& pRoot, Node* nill);
Node* createNode(int key, bool color, Node* nill);
void Insert(Node*& pRoot, int x, Node* nill);

#endif