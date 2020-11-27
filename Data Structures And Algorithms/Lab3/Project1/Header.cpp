#include "Header.h"

dNode* createNode(int x)
{
    dNode* temp = new dNode;
    temp->k = x;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

dList* createList(int x)
{
    dList* result = new dList;

    result->head = NULL;
    result->tail = NULL;

    dNode* temp = createNode(x);

    addHead(result, temp);

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
