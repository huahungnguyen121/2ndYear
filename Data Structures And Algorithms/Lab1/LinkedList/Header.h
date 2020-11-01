#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>

using namespace std;

struct NODE {
	int key;
	NODE* p_next;
};

struct List {
	NODE* p_head;
	NODE* p_tail;
};

NODE* createNode(int data);
List* createList(NODE* p_node);
bool addHead(List*& L, int data);
bool addTail(List*& L, int data);
void removeHead(List*& L);
void removeTail(List*& L);
void removeAll(List*& L);
void printList(List* L);
int countElements(List* L);
List* reverseList(List* L);
void removeDuplicate(List*& L);
bool removeElement(List*& L, int key);

#endif