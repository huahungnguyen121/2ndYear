#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>

using namespace std;

struct Node {
	int key;
	Node* pLeft;
	Node* pRight;
};

//BST
Node* createNode(int data);
int getHeight(Node* pRoot);
void NLR(Node* pRoot);
void LNR(Node* pRoot);
void LRN(Node* pRoot);
void printLevel(Node* pRoot, int level);
void LevelOrder(Node* pRoot);
Node* Search(Node* pRoot, int x);
int countLeaf(Node* pRoot);

#endif