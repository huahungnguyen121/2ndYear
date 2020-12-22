#include "Graph.h"

int main() {
    //initialize Graph
    int n = 10;

    List** l = new List*[n];

    for (int i = 0; i < n; i++)
        l[i] = createList();

    bool* visited = new bool[n];

    for (int i = 0; i < n; i++)
        visited[i] = false;

    addTail(l[0], "2", 1);
    addTail(l[0], "4", 3);
    addTail(l[1], "5", 4);
    addTail(l[2], "6", 5);
    addTail(l[3], "3", 2);
    addTail(l[5], "8", 7);
    addTail(l[5], "9", 8);
    addTail(l[6], "5", 4);
    addTail(l[6], "8", 7);
    addTail(l[9], "8", 7);
    addTail(l[9], "9", 8);

    //free memory
    for (int i = 0; i < n; i++) {
        removeAll(l[i]);
    }
    delete[] l;
    
    return 0;
}