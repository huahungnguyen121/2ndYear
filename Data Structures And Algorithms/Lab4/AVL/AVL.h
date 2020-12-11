#ifndef _AVL_H_
#define _AVL_H_

#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* pLeft;
    Node* pRight;
    int height;
}

Node* createNode(int data);
void Insert(Node* &pRoot, int x);
int getHeight(Node* pRoot);

#endif