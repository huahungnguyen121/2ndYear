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

    addHead(result, x);

    return result;
}

void addHead(dList*& list, int x)
{
    if (!list->head) {
        dNode* temp = createNode(x);
        list->head = temp;
        list->tail = temp;
    }
    else {
        dNode* temp = createNode(x);
        temp->next = list->head;
        list->head->prev = temp;
        list->head = temp;
    }
}
