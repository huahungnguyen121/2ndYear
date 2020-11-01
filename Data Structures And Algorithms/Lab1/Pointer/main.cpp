#include "Header.h"

int main()
{
	int* a;

	a = new int[10];

	for (int i = 0; i < 10; i++)
		a[i] = i + 1;

	cout << RecursiveBinarySearch(a, 0, 10, 4);

	delete[] a;
}