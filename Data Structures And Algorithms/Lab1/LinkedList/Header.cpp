#include "Header.h"

NODE* createNode(int data)
{
    NODE* temp = new NODE;
    temp->key = data;
    temp->p_next = NULL;
    return temp;
}

List* createList(NODE* p_node)
{
    List* temp = new List;
    temp->p_head = p_node;
    for (NODE* p = p_node; p; p = p->p_next)
    {
        if (!p->p_next)
            temp->p_tail = p;
    }
}

bool addHead(List*& L, int data)
{
    NODE* temp = createNode(data);
    temp->p_next = L->p_head;
    L->p_head = temp;
    return true;
}

bool addTail(List*& L, int data)
{
    NODE* temp = createNode(data);
    L->p_tail = temp;
    return true;
}

void removeHead(List*& L)
{
    if (L->p_head == NULL)
        return;

    if (L->p_head->p_next == NULL)
    {
        NODE* temp = L->p_head;
        L->p_head = NULL;
        L->p_tail = NULL;
        delete temp;
        return;
    }

    NODE* temp = L->p_head;
    L->p_head = L->p_head->p_next;
    delete temp;
}

void removeTail(List*& L)
{
    if (L->p_head == NULL)
        return;

    if (L->p_head->p_next == NULL)
    {
        NODE* temp = L->p_head;
        L->p_head = NULL;
        L->p_tail = NULL;
        delete temp;
        return;
    }
    
    NODE* followNode;
    for (NODE* p = L->p_head; p; p = p->p_next)
    {
        if (!p->p_next)
        {
            NODE* temp = L->p_tail;
            L->p_tail = followNode;
            followNode->p_next = NULL;
            delete temp;
            return;
        }
        followNode = p;
    }
}

void removeAll(List*& L)
{
    while (L->p_head) {
        removeHead(L);
    }
}

void printList(List* L)
{
    cout << "\nYour list: \n";
    for (NODE* p = L->p_head; p; p = p->p_next)
        cout << p->key << " ";
    cout << endl;
}

int countElements(List* L)
{
    int count = 0;
    for (NODE* p = L->p_head; p; p = p->p_next)
        count++;
    return count;
}

List* reverseList(List* L)
{
    return nullptr;
}

void removeDuplicate(List*& L)
{
}

bool removeElement(List*& L, int key)
{
    return false;
}
