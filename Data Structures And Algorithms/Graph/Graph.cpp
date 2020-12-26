#include "Graph.h"

//NODE* createNode(string Vertex, int ID)
//{
//    NODE* temp = new NODE;
//    temp->Vertex = Vertex;
//    temp->ID = ID;
//    temp->p_next = NULL;
//    return temp;
//}
//
//List* createList()
//{
//    List* temp = new List;
//    temp->p_head = NULL;
//    temp->p_tail = NULL;
//    return temp;
//}
//
//bool addHead(List*& L, string Vertex, int ID)
//{
//	if (L->p_head == NULL && L->p_tail == NULL)
//	{
//		NODE* temp = createNode(Vertex, ID);
//		temp->p_next = L->p_head;
//		L->p_head = temp;
//		L->p_tail = temp;
//		return true;
//	}
//
//    NODE* temp = createNode(Vertex, ID);
//    temp->p_next = L->p_head;
//    L->p_head = temp;
//    return true;
//}
//
//bool addTail(List*& L, string Vertex, int ID)
//{
//    if (L->p_head == NULL && L->p_tail == NULL)
//    {
//        addHead(L, Vertex, ID);
//        return true;
//    }
//    
//  
//    NODE* temp = createNode(Vertex, ID);
//    L->p_tail->p_next = temp;
//    L->p_tail = temp;
//    return true;
//}
//
//void removeHead(List*& L)
//{
//    if (L->p_head == NULL)
//        return;
//
//    if (L->p_head->p_next == NULL)
//    {
//        NODE* temp = L->p_head;
//        L->p_head = NULL;
//        L->p_tail = NULL;
//        delete temp;
//        return;
//    }
//
//    NODE* temp = L->p_head;
//    L->p_head = L->p_head->p_next;
//    delete temp;
//}
//
//void removeTail(List*& L)
//{
//    if (L->p_head == NULL)
//        return;
//
//    if (L->p_head->p_next == NULL)
//    {
//        NODE* temp = L->p_head;
//        L->p_head = NULL;
//        L->p_tail = NULL;
//        delete temp;
//        return;
//    }
//    
//    NODE* followNode = NULL;
//    for (NODE* p = L->p_head; p; p = p->p_next)
//    {
//        if (!p->p_next)
//        {
//            NODE* temp = L->p_tail;
//            L->p_tail = followNode;
//            followNode->p_next = NULL;
//            delete temp;
//            return;
//        }
//        followNode = p;
//    }
//}
//
//void removeAll(List*& L)
//{
//    while (L->p_head) {
//        removeHead(L);
//    }
//}
//
//void printList(List* L)
//{
//    cout << "\nYour list: \n";
//    for (NODE* p = L->p_head; p; p = p->p_next)
//        cout << p->Vertex << " ";
//    cout << endl;
//}

vector<bool> readLine(string data) {
	vector<bool> result;
	int startPos = 0;
	while (true)
	{
		size_t foundPos = data.find(" ", startPos);
		if (foundPos != string::npos)
		{
			string token = data.substr(startPos, foundPos - startPos);
			if (token != "") {
				if (token == "0")
					result.push_back(false);
				if (token == "1")
					result.push_back(true);
			}

			startPos = foundPos + 1;
		}
		else
		{
			string token = data.substr(startPos, foundPos - startPos);
			if (token != "") {
				if (token == "0")
					result.push_back(false);
				if (token == "1")
					result.push_back(true);
			}
			break;
		}
	}
	return result;
}

void initGraph(bool**& graph, int& n) {
	fstream f;

	f.open("D:\\Code\\2ndYear\\Data Structures And Algorithms\\Graph\\input.txt", ios::in);

	string buff = "";

	getline(f, buff, '\n');

	n = stoi(buff);
	
	graph = new bool* [n];
	for (int i = 0; i < n; i++)
		graph[i] = new bool[n];

	for (int i = 0; i < n; i++) {
		getline(f, buff, '\n');
		vector<bool> temp = readLine(buff);
		for (int j = 0; j < n; j++)
			graph[i][j] = temp[j];
	}

	f.close();
}

void DFT(bool** graph, int v, bool visited[], int n) {
    stack<int> s;
    s.push(v);
	visited[v] = true;
	cout << v + 1 << " ";
    while (!s.empty()) {
		int u = s.top();
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (graph[u][i]) {
				if (!visited[i]) {
					s.push(i);
					visited[i] = true;
					flag = true;
					cout << i + 1 << " ";
					break;
				}
			}
		}
		if (!flag)
			s.pop();
    }
}

void BFT(bool** graph, int n) {
    bool* visited = new bool[n];

    for (int i = 0; i < n; i++)
        visited[i] = false;

    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            q.push(i);
			cout << i + 1 << " ";
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int j = 0; j < n; j++) {
					if (graph[u][j]) {
						if (!visited[j]) {
							q.push(j);
							cout << j + 1 << " ";
							visited[j] = true;
						}
					}
				}
			}
        }
    }

	delete[] visited;
}

void dftTree(bool** graph, int v, bool visited[], int n) {
	stack<int> s;
	s.push(v);
	visited[v] = true;
	while (!s.empty()) {
		int u = s.top();
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (graph[u][i]) {
				if (!visited[i]) {
					s.push(i);
					visited[i] = true;
					flag = true;
					cout << u + 1 << "-" << i + 1 << " ";
					break;
				}
			}
		}
		if (!flag)
			s.pop();
	}
}

void bftTree(bool** graph, int n) {
	bool* visited = new bool[n];

	for (int i = 0; i < n; i++)
		visited[i] = false;

	queue<int> q;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			q.push(i);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int j = 0; j < n; j++) {
					if (graph[u][j]) {
						if (!visited[j]) {
							q.push(j);
							visited[j] = true;
							cout << u + 1 << "-" << j + 1 << " ";
						}
					}
				}
			}
		}
	}

	delete[] visited;
}