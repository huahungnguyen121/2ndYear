#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>

using namespace std;

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
dList* createList();
void addHead(dList*& list, dNode*& pNode);
void addTail(dList*& list, dNode*& pNode);
void addBefore(dNode*& pos, dNode*& pAdd);
void addAfter(dNode*& pos, dNode*& pAdd);
void removeHead(dList*& list);
void removeTail(dList*& list);
// return true if remove successfully
bool removeWithValue(dList*& list, int key);
void freeList(dList*& list);
// flag false to print reverse list
void printList(dList*& list, bool order);

#endif