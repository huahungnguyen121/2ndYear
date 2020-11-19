#include "Header.h"

float bubbleSort(int a[], int n)
{
	clock_t start = clock();
	for (int i = 1; i < n; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
		}
	}
	clock_t end = clock();

	return (float)(end - start) / CLOCKS_PER_SEC;
}

int findMin(int a[], int start, int n)
{
	int Min = start;
	for (int i = start + 1; i < n; i++)
		if (a[i] < a[Min])
			Min = i;
	return Min;
}

float selectionSort(int a[], int n)
{
	clock_t start = clock();
	for (int i = 0; i < n - 1; i++)
	{
		int Min = findMin(a, i, n);
		swap(a[i], a[Min]);
	}
	clock_t end = clock();

	return (float)(end - start) / CLOCKS_PER_SEC;
}

float insertionSort(int a[], int n)
{
	clock_t start = clock();
	int k = 1;
	while (k < n) {
		int i = k - 1;
		int p = a[k];
		while (i > -1 && a[i] > p)
		{
			a[i + 1] = a[i];
			i--;
		}
		i++;
		a[i] = p;
		k++;
	}
	clock_t end = clock();

	return (float)(end - start) / CLOCKS_PER_SEC;
}

void sift(int a[], int left, int right)
{
	int i = left;
	int j = 2 * i + 1;
	int x = a[i];
	while (j <= right) {
		if ((a[j] < a[j + 1]) && j < right)
			j++;
		if (x >= a[j])
			break;
		a[i] = a[j];
		i = j;
		j = 2 * i + 1;
	}
	a[i] = x;
}

float heapSort(int a[], int n)
{
	clock_t start = clock();
	int left = n / 2 - 1;
	while (left > -1) {
		sift(a, left, n - 1);
		left--;
	}

	int right = n - 1;
	while (right > 0) {
		swap(a[0], a[right]);
		right--;
		sift(a, 0, right);
	}

	clock_t end = clock();

	return (float)(end - start) / CLOCKS_PER_SEC;
}

int partition(int a[], int left, int right)
{
	int mid = left + (right - left) / 2;
	int p = a[mid];
	int i = left - 1;
	int j = right + 1;
	do {
		do
			i++;
		while (a[i] < p);
		do
			j--;
		while (a[j] > p);
		swap(a[i], a[j]);
	} while (i < j);
	swap(a[i], a[j]);
	return j;
}

float quickSort(int a[], int left, int right)
{
	clock_t start = clock();
	if (left < right) {
		int s = partition(a, left, right);
		quickSort(a, left, s);
		quickSort(a, s + 1, right);
		clock_t end = clock();

		return (float)(end - start) / CLOCKS_PER_SEC;
	}
	clock_t end = clock();

	return (float)(end - start) / CLOCKS_PER_SEC;
}

Node* createNode(int k)
{
	Node* temp = new Node;
	temp->next = NULL;
	temp->key = k;
	return temp;
}

Bin* newBin(int id)
{
	Bin* temp = new Bin;
	temp->id = id;
	temp->head = NULL;
	temp->tail = NULL;
	temp->next = NULL;
	return temp;
}

int getDigit(int data, int k)
{
	for (int i = 0; i < k; i++)
		data /= 10;
	return data % 10;
}

int getMaxDigit(int a[], int n)
{
	int max = a[0];

	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];

	int count = 0;
	while (max != 0) {
		count++;
		max /= 10;
	}

	return count;
}

void createBins(int a[], int n, int k, Bin*& b)
{
	for (int i = 0; i < n; i++) {
		int id = getDigit(a[i], k);
		Bin* temp = b;
		Bin* temp2 = b->next;
		while (temp2 && temp2->id < id) {
			temp = temp->next;
			temp2 = temp2->next;
		}
		if (!temp2 || temp2->id != id) {
			Bin* addBin = newBin(id);
			temp->next = addBin;
			addBin->next = temp2;
		}
		if (temp2 && temp2->id > id) {
			Bin* addBin = newBin(id);
			temp->next = addBin;
			addBin->next = temp2;
		}
	}
}

void freeBins(Bin*& b)
{
	while (b) {
		Bin* temp = b;
		b = b->next;
		delete temp;
	}

	b = newBin(-1);
}

float radixSort(int a[], int n)
{
	clock_t start = clock();
	Bin* bins = newBin(-1);
	int d = getMaxDigit(a, n);

	for (int i = 0; i < d; i++) {
		createBins(a, n, i, bins);
		for (int j = 0; j < n; j++) {
			int temp = getDigit(a[j], i);
			Node* buffer = createNode(a[j]);
			Bin* run = bins->next;
			while (run->id != temp) {
				run = run->next;
			}
			if (!run->head) {
				run->head = buffer;
				run->tail = buffer;
			}
			else {
				run->tail->next = buffer;
				run->tail = buffer;
			}
		}

		Bin* run = bins->next;
		int k = 0;
		while (run) {
			for (Node* p = run->head; p; p = p->next) {
				a[k] = p->key;
				k++;
			}
			run = run->next;
		}
		freeBins(bins);
	}

	delete bins;
	clock_t end = clock();

	return (float)(end - start) / CLOCKS_PER_SEC;
}

void merge(int a[], int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* tempArray1 = new int[n1];
	int* tempArray2 = new int[n2];

	for (int i = 0; i < n1; i++)
		tempArray1[i] = a[left + i];

	for (int i = 0; i < n2; i++)
		tempArray2[i] = a[left + n1 + i];

	int i = 0;
	int j = 0;
	int k = left;

	while (i < n1 && j < n2) {
		if (tempArray1[i] < tempArray2[j]) {
			a[k++] = tempArray1[i++];
		}
		else
			a[k++] = tempArray2[j++];
	}

	if (i == n1) {
		while (j < n2) {
			a[k++] = tempArray2[j++];
		}
		delete[] tempArray1;
		delete[] tempArray2;
		return;
	}
	if (j == n2) {
		while (i < n1) {
			a[k++] = tempArray1[i++];
		}
		delete[] tempArray1;
		delete[] tempArray2;
		return;
	}
}

float mergeSort(int a[], int left, int right) {
	clock_t start = clock();
	if (left < right) {
		int mid = (right + left) / 2;

		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);

		merge(a, left, mid, right);
	}
	clock_t end = clock();

	return (float)(end - start) / CLOCKS_PER_SEC;
}