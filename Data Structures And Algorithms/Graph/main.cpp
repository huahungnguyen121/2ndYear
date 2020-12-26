#include "Graph.h"

int main() {
    //initialize Graph
    int n = 0;

	bool** graph = NULL;

	//read matrix from input.txt 
	initGraph(graph, n);

	bool* visited = new bool[n];

	for (int i = 0; i < n; i++)
		visited[i] = false;

	//DFT
	for (int i = 0; i < n; i++)
		if (!visited[i])
			DFT(graph, i, visited, n);

	cout << endl;

	//renew
	for (int i = 0; i < n; i++)
		visited[i] = false;

	for (int i = 0; i < n; i++)
		if (!visited[i])
			dftTree(graph, i, visited, n);

	cout << endl;

	//BFT
	BFT(graph, n);

	cout << endl;

	//BFT
	bftTree(graph, n);

	cout << endl;

	//free memory
	for (int i = 0; i < n; i++)
		delete[] graph[i];
	delete[] graph;
    
	delete[] visited;
    return 0;
}