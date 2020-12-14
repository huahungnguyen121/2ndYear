#include "AVL.h"

int main() {
    Node* p = NULL;

    Insert(p, 962);
    Insert(p, 455);
    Insert(p, 662);
    Insert(p, 367);
    Insert(p, 765);
    Insert(p, 58);
    Insert(p, 786);
    Insert(p, 938);
    Insert(p, 306);
    Insert(p, 123);
    Insert(p, 400);
    Insert(p, 500);
    Insert(p, 777);
    Insert(p, 1000);
    Insert(p, 19);
    Insert(p, 399);
    Insert(p, 450);
    Insert(p, 499);
    Insert(p, 550);
    Insert(p, 900);
    Insert(p, 451);
    Insert(p, 600);

    Remove(p, 123);
    //Remove(p, 765);

    // Insert(p, 4);
    // Insert(p, 2);
    // Insert(p, 7);
    // Insert(p, 1);
    // Insert(p, 3);
    // Insert(p, 5);
    // Insert(p, 9);
	// Insert(p, 8);
    // Insert(p, 14);
    // Insert(p, 10);
    // Insert(p, 6);
	// Insert(p, 17);
	// Insert(p, 16);

    //Remove(p, 8);
    
    //cout << isAVL(p);
    //LevelOrder(p);
    NLR(p);
    
    release(p);
    return 0;
}