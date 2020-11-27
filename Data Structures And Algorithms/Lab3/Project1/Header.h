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
void addHead(dList*& list, int x);

#endif