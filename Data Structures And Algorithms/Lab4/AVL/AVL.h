#ifndef _AVL_H_
#define _AVL_H_

#include <iostream>
#include <climits>

using namespace std;

struct Node {
    int key;
    Node* pLeft;
    Node* pRight;
    int height;
};

void release(Node*& pRoot);
Node* createNode(int data);
void rotateLeft(Node*& pRoot);
void rotateRight(Node*& pRoot);
void rotate(Node*& pRoot);
void Insert(Node* &pRoot, int x);
int getHeight(Node* pRoot);
void NLR(Node* pRoot);
void LNR(Node* pRoot);
void LRN(Node* pRoot);
void printLevel(Node* pRoot, int level);
void LevelOrder(Node* pRoot);
void findSuccessor(Node*& pRoot, Node*& q);
void Remove(Node*& pRoot, int x);
int findMax(Node* pRoot);
int findMin(Node* pRoot);
bool isAVL(Node* pRoot);

#endif