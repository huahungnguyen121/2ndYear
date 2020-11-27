#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>

struct dNode {
	int k;
	dNode* next;
	dNode* prev;
};

struct dList {
	dNode* head;
	dNode* tail;
};

dNode* createNode(int x);
dList* createList(int x);
void addHead(dList*& list, dNode*& pNode);
void addTail(dList*& list, dNode*& pNode);
void addBefore(dNode*& pos, dNode*& pAdd);
void addAfter(dNode*& pos, dNode*& pAdd);

#endif