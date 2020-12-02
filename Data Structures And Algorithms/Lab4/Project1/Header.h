#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>

using namespace std;

struct Node {
	int key;
	Node* pLeft;
	Node* pRight;
};

Node* createNode(int data);
int getHeight(Node* pRoot);
void NLR(Node* pRoot);
void LNR(Node* pRoot);
void LRN(Node* pRoot);
void printLevel(Node* pRoot, int level);
void LevelOrder(Node* pRoot);

#endif