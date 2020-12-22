#include "Graph.h"

NODE* createNode(string Vertex, int ID)
{
    NODE* temp = new NODE;
    temp->Vertex = Vertex;
    temp->ID = ID;
    temp->p_next = NULL;
    return temp;
}

List* createList()
{
    List* temp = new List;
    temp->p_head = NULL;
    temp->p_tail = NULL;
    return temp;
}

bool addHead(List*& L, string Vertex, int ID)
{
    NODE* temp = createNode(Vertex, ID);
    temp->p_next = L->p_head;
    L->p_head = temp;
    return true;
}

bool addTail(List*& L, string Vertex, int ID)
{
    if (L->p_head == NULL && L->p_tail == NULL)
    {
        addHead(L, Vertex, ID);
        return true;
    }
    
  
    NODE* temp = createNode(Vertex, ID);
    L->p_tail->p_next = temp;
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
    
    NODE* followNode = NULL;
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
        cout << p->Vertex << " ";
    cout << endl;
}

void DFT(List* graph[], int v, bool visited[]) {
    visited[v] = true;
    stack<int> s;
    s.push(v);
    while (!s.empty()) {
        int u = s.top();
        cout << u << " ";
        NODE* p = graph[u]->p_head;
        while (p) {
            if (!visited[p->ID]) {
                visited[p->ID] = true;
                s.push(p->ID);
            }
            p = p->p_next;
        }
    }
}