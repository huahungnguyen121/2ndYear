#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <iomanip>

using namespace std;

struct Node {
	int key;
	Node* next;
};

struct Bin {
	int id;
	Node* head;
	Node* tail;
	Bin* next;
};

float bubbleSort(int a[], int n);
int findMin(int a[], int start, int n);
float selectionSort(int a[], int n);
float insertionSort(int a[], int n);
void sift(int a[], int left, int right);
float heapSort(int a[], int n);
int partition(int a[], int left, int right);
float quickSort(int a[], int left, int right);
Node* createNode(int k);
Bin* newBin(int id);
int getDigit(int data, int k);
int getMaxDigit(int a[], int n);
void createBins(int a[], int n, int k, Bin*& b);
void freeBins(Bin*& b);
float radixSort(int a[], int n);
void merge(int a[], int left, int mid, int right);
float mergeSort(int a[], int left, int right);

#endif