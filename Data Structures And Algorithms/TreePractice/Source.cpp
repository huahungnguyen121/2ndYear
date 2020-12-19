#include <iostream>
#include <climits>
#include <queue>

using namespace std;

struct Node {
    int key;
    Node* pLeft;
    Node* pRight;
    int height;
};

void release(Node*& pRoot);
Node* createNode(int data);
void rotateLeft(Node*& pRoot);
void rotateRight(Node*& pRoot);
void rotate(Node*& pRoot);
void Insert(Node* &pRoot, int x);
int getHeight(Node* pRoot);
void NLR(Node* pRoot);
void LNR(Node* pRoot);
void LRN(Node* pRoot);
void LevelOrder(Node* pRoot);
void fixHeight(Node*& pRoot);
void findSuccessor(Node*& pRoot, Node*& q);
void Remove(Node*& pRoot, int x);
int findMax(Node* pRoot);
int findMin(Node* pRoot);
bool isAVL(Node* pRoot);

void release(Node*& pRoot) {
    if (pRoot) {
        Node* p1 = pRoot->pLeft;
        Node* p2 = pRoot->pRight;
        delete pRoot;
        release(p1);
        release(p2);
    }
}

Node* createNode(int data) {
    Node* result = new Node;
    result->key = data;
    result->pLeft = NULL;
    result->pRight = NULL;
    result->height = 1;
    return result;
}

void rotateLeft(Node*& pRoot) {
    Node* p1 = pRoot;
    Node* p2 = pRoot->pRight;
    p1->pRight = p2->pLeft;
    p1->height = getHeight(p1);
    p2->pLeft = p1;
    p2->height = getHeight(p2);
    pRoot = p2;
}

void rotateRight(Node*& pRoot) {
    Node* p1 = pRoot;
    Node* p2 = pRoot->pLeft;
    p1->pLeft = p2->pRight;
    p1->height = getHeight(p1);
    p2->pRight = p1;
    p2->height = getHeight(p2);
    pRoot = p2;
}

void rotate(Node*& pRoot) {
	if (pRoot) {
		int hLeft = (pRoot->pLeft) ? pRoot->pLeft->height : 0;
		int hRight = (pRoot->pRight) ? pRoot->pRight->height : 0;

		if (hLeft - hRight > 1) {
			int hLeft1 = (pRoot->pLeft->pLeft) ? pRoot->pLeft->pLeft->height : 0;
			int hRight1 = (pRoot->pLeft->pRight) ? pRoot->pLeft->pRight->height : 0;
			if (hLeft1 - hRight1 >= 0) {
				rotateRight(pRoot);
			}
			else {
				rotateLeft(pRoot->pLeft);
				rotateRight(pRoot);
			}
		}

		if (hLeft - hRight < -1) {
			int hLeft1 = (pRoot->pRight->pLeft) ? pRoot->pRight->pLeft->height : 0;
			int hRight1 = (pRoot->pRight->pRight) ? pRoot->pRight->pRight->height : 0;
			if (hLeft1 - hRight1 <= 0) {
				rotateLeft(pRoot);
			}
			else {
				rotateRight(pRoot->pRight);
				rotateLeft(pRoot);
			}
		}
	}
}

void Insert(Node* &pRoot, int x) {
    if (!pRoot) {
        pRoot = createNode(x);
    }
    else {
        if (pRoot->key < x) {
            Insert(pRoot->pRight, x);
            pRoot->height = getHeight(pRoot);
        }
        else {
            if (pRoot->key > x) {
                Insert(pRoot->pLeft, x);
                pRoot->height = getHeight(pRoot);
            }
            else {
                cout << x << " existed";
                return;
            }
        }
    }

    rotate(pRoot);
}

int getHeight(Node* pRoot)
{
	if (pRoot) {
		int left = getHeight(pRoot->pLeft);
		int right = getHeight(pRoot->pRight);

		if (left > right)
			return 1 + left;
		else return 1 + right;
	}
	else return 0;
}

void NLR(Node* pRoot)
{
	if (pRoot) {
		cout << pRoot->key << " h = " << pRoot->height << ", ";
		NLR(pRoot->pLeft);
		NLR(pRoot->pRight);
	}
}

void LNR(Node* pRoot)
{
	if (pRoot) {
		LNR(pRoot->pLeft);
		cout << pRoot->key << " h = " << pRoot->height << ", ";
		LNR(pRoot->pRight);
	}
}

void LRN(Node* pRoot)
{
	if (pRoot) {
		LRN(pRoot->pLeft);
		LRN(pRoot->pRight);
		cout << pRoot->key << " h = " << pRoot->height << ", ";
	}
}

void LevelOrder(Node* pRoot)
{
	if (!pRoot)
        return;
    queue<Node*> q;
    q.push(pRoot);
    
    while (!q.empty()) {
        Node* fr = q.front();
        cout << fr->key << " h = " << fr->height << " ";
        if (fr->pLeft)
            q.push(fr->pLeft);
        if (fr->pRight)
            q.push(fr->pRight);
        q.pop();
    }
}

void fixHeight(Node*& pRoot) {
    while (pRoot) {
        pRoot->height = getHeight(pRoot);
        pRoot = pRoot->pLeft;
    }
}

void findSuccessor(Node*& pRoot, Node*& q) {
    Node* p = pRoot;
    while (pRoot->pLeft) {
        pRoot = pRoot->pLeft;
    }
    q->key = pRoot->key;
    q = pRoot;
    pRoot = pRoot->pRight;
    pRoot = p;
}

void Remove(Node*& pRoot, int x) {
    if (!pRoot) {
        cout << x << " does not exist";
        return;
    }
    else {
        if (pRoot->key < x) {
            Remove(pRoot->pRight, x);
            pRoot->height = getHeight(pRoot);
        }
        else {
            if (pRoot->key > x) {
                Remove(pRoot->pLeft, x);
                pRoot->height = getHeight(pRoot);
            }
            else {
                Node* q = pRoot;
                if (!q->pLeft) {
                    pRoot = q->pRight;
					delete q;
                }
                else {
                    if (!q->pRight) {
                        pRoot = q->pLeft;
						delete q;
                    }
                    else {
                        findSuccessor(pRoot->pRight, q);
                        Remove(pRoot->pRight, pRoot->key);
                    }
                }
                if (pRoot) {
					pRoot->height = getHeight(pRoot);
                    fixHeight(pRoot->pRight);
                }
            }
        }
    }

    rotate(pRoot);
}

int findMax(Node* pRoot) {
    if (!pRoot)
        return INT_MIN;
    int max = pRoot->key;
    int leftMax = findMax(pRoot->pLeft);
    int rightMax = findMax(pRoot->pRight);

    if (leftMax > max)
        max = leftMax;
    if (rightMax > max)
        max = rightMax;
    return max;
}

int findMin(Node* pRoot) {
    if (!pRoot)
        return INT_MAX;
    int min = pRoot->key;
    int leftMin = findMin(pRoot->pLeft);
    int rightMin = findMin(pRoot->pRight);

    if (leftMin < min)
        min = leftMin;
    if (rightMin < min)
        min = rightMin;
    return min;
}

bool isAVL(Node* pRoot) {
    if (pRoot) {
        int hLeft = (pRoot->pLeft) ? pRoot->pLeft->height : 0;
		int hRight = (pRoot->pRight) ? pRoot->pRight->height : 0;

        if (hLeft - hRight > 1 || hLeft - hRight < -1)
            return false;
        
        int maxLeft = findMax(pRoot->pLeft);
        int minRight = findMin(pRoot->pRight);

        if (maxLeft >= pRoot->key || minRight <= pRoot->key)
            return false;
        
        return isAVL(pRoot->pLeft) && isAVL(pRoot->pRight);
    }
    else
        return true;
}

long long sumNode(Node* pRoot) {
    long long sum = 0;
    if (!pRoot)
        return sum;
    
    queue<Node*> q;
    q.push(pRoot);
    
    while (!q.empty()) {
        Node* fr = q.front();
        sum += fr->key;
        if (fr->pLeft)
            q.push(fr->pLeft);
        if (fr->pRight)
            q.push(fr->pRight);
        q.pop();
    }

    return sum;
}

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
    Remove(p, 765);

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
    //NLR(p);

    cout << sumNode(p);
    
    release(p);
    return 0;
}