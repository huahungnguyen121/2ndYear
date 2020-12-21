#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Node {
	int key;
	Node* pLeft;
	Node* pRight;
};

Node* createNode(int data)
{
	Node* temp = new Node;
	temp->key = data;
	temp->pLeft = NULL;
	temp->pRight = NULL;
	return temp;
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

void readFile(vector<string>& a, int& h, int& c, int& m) {
	fstream f;

	f.open("input.txt", ios::in);

	string temp = "";

	getline(f, temp, '.');

	a = split(temp, " ");

	f.ignore(1);

	getline(f, temp, ' ');

	h = stoi(temp);

	getline(f, temp, '\n');

	c = stoi(temp);

	getline(f, temp, '\n');

	m = stoi(temp);

	f.close();
}

void Insert(Node*& pRoot, int x) {
	if (!pRoot) {
		pRoot = createNode(x);
	}
	else {
		if (pRoot->key < x) {
			Insert(pRoot->pRight, x);
		}
		else {
			if (pRoot->key > x) {
				Insert(pRoot->pLeft, x);
			}
			else {
				cout << x << " existed";
				return;
			}
		}
	}
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
		cout << pRoot->key << " ";
		NLR(pRoot->pLeft);
		NLR(pRoot->pRight);
	}
}

int sumNode(Node* pRoot, int h, int c) {
	if (pRoot) {
		if (pRoot->key > c && getHeight(pRoot) == h) {
			return pRoot->key + sumNode(pRoot->pLeft, h, c) + sumNode(pRoot->pRight, h, c);
		}
		else
			return sumNode(pRoot->pLeft, h, c) + sumNode(pRoot->pRight, h, c);
	}
	else
		return 0;
}


int main() {
	vector<string> a;
	int h;
	int c;
	int m;
	Node* pRoot = NULL;
	readFile(a, h, c, m);

	for (int i = 0; i < a.size(); i++) {
		Insert(pRoot, stoi(a[i]));
	}

	NLR(pRoot);

	cout << endl;

	cout << sumNode(pRoot, h, c);

	return 0;
}