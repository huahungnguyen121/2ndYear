#include "AVL.h"

int main() {
    Node* p = NULL;

    Insert(p, 4);
    Insert(p, 2);
    Insert(p, 7);
    Insert(p, 1);
    Insert(p, 3);
    Insert(p, 5);
    Insert(p, 9);
	Insert(p, 8);
    Insert(p, 14);
    Insert(p, 10);
    Insert(p, 6);
	Insert(p, 17);
	Insert(p, 16);

    Remove(p, 8);
    
    cout << isAVL(p);
    //LevelOrder(p);
    
    release(p);
    return 0;
}