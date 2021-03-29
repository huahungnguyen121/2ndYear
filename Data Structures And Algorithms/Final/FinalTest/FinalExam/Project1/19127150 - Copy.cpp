#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int key;
    Node* pLeft;
    Node* pRight;
    int height;
};

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

void Insert(Node*& pRoot, int x) {
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

void LRN(Node* pRoot)
{
    if (pRoot) {
        LRN(pRoot->pLeft);
        LRN(pRoot->pRight);
        cout << pRoot->key << " h = " << pRoot->height << ", ";
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

vector<string> split(string haystack, string separator)
{
	vector<string> tokens;
	int startPos = 0;

	if (separator == " ")
	{
		while (true)
		{
			size_t foundPos = haystack.find(separator, startPos);
			if (foundPos != string::npos)
			{
				string token = haystack.substr(startPos, foundPos - startPos);
				if (token != "")
					tokens.push_back(token);

				startPos = foundPos + separator.length();
			}
			else
			{
				string token = haystack.substr(startPos, foundPos - startPos);
				if (token != "")
					tokens.push_back(token);
				break;
			}
		}

		return tokens;
	}

	while (true)
	{
		size_t foundPos = haystack.find(separator, startPos);
		if (foundPos != string::npos)
		{
			string token = haystack.substr(startPos, foundPos - startPos);
			tokens.push_back(token);

			startPos = foundPos + separator.length();
		}
		else
		{
			string token = haystack.substr(startPos, foundPos - startPos);
			tokens.push_back(token);
			break;
		}
	}

	return tokens;
}

void readFile(vector<string>& a, int& n, int& num) {
	fstream f;

	f.open("input.txt", ios::in);

	string temp = "";

	getline(f, temp, '\n');

    n = stoi(temp);

	getline(f, temp, '\n');

	a = split(temp, " ");

	getline(f, temp, '\n');

	num = stoi(temp);

	f.close();
}

int sumTree(Node* pRoot) {
    if (pRoot) {
        return pRoot->key + sumTree(pRoot->pRight) + sumTree(pRoot->pLeft);
    }
    else return 0;
}

void findNode(Node* pRoot, vector<int>& a, int num) {
    if (pRoot) {
        if (sumTree(pRoot) - pRoot->key < num)
            a.push_back(pRoot->key);
        findNode(pRoot->pLeft, a, num);
        findNode(pRoot->pRight, a, num);
    }
}

void Sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
                swap(a[i], a[j]);
        }
    }
}

void printNode(Node* pRoot, int num) {
    vector<int> a;

    findNode(pRoot, a, num);

    int n = a.size();
    int* temp = new int[n];

    for (int i = 0; i < n; i++)
        temp[i] = a[i];

    Sort(temp, n);

    for (int i = 0; i < n; i++)
        cout << temp[i] << " ";

    delete[] temp;
}

int main() {
    vector<string> a;
    int n = 0;
    int num = 0;

    readFile(a, n, num);

    Node* pRoot = NULL;

    for (int i = 0; i < n; i++)
        Insert(pRoot, stoi(a[i]));

    LRN(pRoot);

    cout << endl;

    printNode(pRoot, num);

    release(pRoot);

	return 0;
}