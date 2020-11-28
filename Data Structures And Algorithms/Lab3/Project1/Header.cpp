#include "Header.h"

dNode* createNode(int x)
{
    dNode* temp = new dNode;
    temp->k = x;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

dList* createList()
{
    dList* result = new dList;

    result->head = NULL;
    result->tail = NULL;

    return result;
}

void addHead(dList*& list, dNode*& pNode)
{
    if (!list->head) {
        list->head = pNode;
        list->tail = pNode;
    }
    else {
        pNode->next = list->head;
        list->head->prev = pNode;
        list->head = pNode;
    }
}

void addTail(dList*& list, dNode*& pNode)
{
    if (!list->head) {
        list->head = pNode;
        list->tail = pNode;
    }
    else {
        pNode->prev = list->tail;
        list->tail->next = pNode;
        list->tail = pNode;
    }
}

void addBefore(dNode*& pos, dNode*& pAdd)
{
    if (!pos->prev) {
        pos->prev = pAdd;
        pAdd->next = pos;
    }
    else {
        pAdd->prev = pos->prev;
        pAdd->next = pos;
        pos->prev->next = pAdd;
        pos->prev = pAdd;
    }
}

void addAfter(dNode*& pos, dNode*& pAdd)
{
    if (!pos->next) {
        pos->next = pAdd;
        pAdd->prev = pos;
    }
    else {
        pAdd->prev = pos;
        pAdd->next = pos->next;
        pos->next->prev = pAdd;
        pos->next = pAdd;
    }
}

void removeHead(dList*& list)
{
	if (!list->head)
		return;
	else {
		if (list->head == list->tail) {
			dNode* temp = list->head;
			list->head = NULL;
			list->tail = NULL;
			delete temp;
		}
		else {
			dNode* temp = list->head;
			list->head = list->head->next;
			list->head->prev = NULL;
			delete temp;
		}
	}
}

void removeTail(dList*& list)
{
	if (!list->head)
		return;
	else {
		if (list->head == list->tail) {
			dNode* temp = list->head;
			list->head = NULL;
			list->tail = NULL;
			delete temp;
		}
		else {
			dNode* temp = list->tail;
			list->tail = list->tail->prev;
			list->tail->next = NULL;
			delete temp;
		}
	}
}

bool removeWithValue(dList*& list, int key)
{
	dNode* p = list->head;
	
	while (p) {
		if (p->k == key) {
			dNode* temp = p;
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete temp;
			return true;
		}
		p = p->next;
	}

	return false;
}

void freeList(dList*& list)
{
	dNode* p = list->head;

	while (p) {
		removeHead(list);
		p = list->head;
	}
}

void printList(dList*& list, bool order)
{
	if (order) {
		for (dNode* p = list->head; p; p = p->next)
			cout << p->k << " ";
	}
	else {
		for (dNode* p = list->tail; p; p = p->prev)
			cout << p->k << " ";
	}
}
