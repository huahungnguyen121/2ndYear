#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//struct NODE {
//	string Vertex;
//    int ID;
//	NODE* p_next;
//};
//
//struct List {
//	NODE* p_head;
//	NODE* p_tail;
//};
//
////linkedlist
//NODE* createNode(string Vertex, int ID);
//List* createList();
//bool addHead(List*& L, string Vertex, int ID);
//bool addTail(List*& L, string Vertex, int ID);
//void removeHead(List*& L);
//void removeTail(List*& L);
//void removeAll(List*& L);

//graph
vector<bool> readLine(string data);
void initGraph(bool**& graph, int& n);
void DFT(bool** graph, int v, bool visited[], int n);
void BFT(bool** graph, int n);
void dftTree(bool** graph, int v, bool visited[], int n);
void bftTree(bool** graph, int n);

#endif