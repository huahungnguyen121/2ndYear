#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
using namespace std;

float bubbleSort(int a[], int n);
int findMin(int a[], int start, int n);
float selectionSort(int a[], int n);
float insertionSort(int a[], int n);
void sift(int a[], int left, int right);
float heapSort(int a[], int n);

#endif