#include "Header.h"

template <class T>
void HoanVi(T& a, T& b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

int main() {
	int n = 3000;

	int *a = new int[n];
	int *b = new int[n];
	int *c = new int[n];
	int *d = new int[n];
	//int e[100];

	GenerateData(a, n, 0);
	GenerateData(b, n, 1);
	GenerateData(c, n, 2);
	GenerateData(d, n, 3);
	//GenerateData(e, 100, 0);

	//for (int i = 0; i < 10; i++)
	//	cout << e[i] << endl;

	//cout << endl;

	/*float ranTime = quickSort(a, 0, n - 1);
	float sortedTime = quickSort(b, 0, n - 1);
	float reverseTime = quickSort(c, 0, n - 1);
	float nearlySortedTime = quickSort(d, 0, n - 1);*/

	//radixSort(e, 100);

	/*float ranTime = radixSort(a, n);
	float sortedTime = radixSort(b, n);
	float reverseTime = radixSort(c, n);
	float nearlySortedTime = radixSort(d, n);*/

	float ranTime = heapSort(a, n);
	float sortedTime = heapSort(b, n);
	float reverseTime = heapSort(c, n);
	float nearlySortedTime = heapSort(d, n);

	/*float ranTime = mergeSort(a, 0, n - 1);
	float sortedTime = mergeSort(b, 0, n - 1);
	float reverseTime = mergeSort(c, 0, n - 1);
	float nearlySortedTime = mergeSort(d, 0, n - 1);*/

	/*float ranTime = bubbleSort(a, n);
	float sortedTime = bubbleSort(b, n);
	float reverseTime = bubbleSort(c, n);
	float nearlySortedTime = bubbleSort(d, n);*/

	/*float ranTime = selectionSort(a, n);
	float sortedTime = selectionSort(b, n);
	float reverseTime = selectionSort(c, n);
	float nearlySortedTime = selectionSort(d, n);*/

	/*float ranTime = insertionSort(a, n);
	float sortedTime = insertionSort(b, n);
	float reverseTime = insertionSort(c, n);
	float nearlySortedTime = insertionSort(d, n);*/


	cout << "Random " << n << " elements are sorted in " << setprecision(15) << fixed << ranTime << " second(s)\n";
	cout << "Sorted " << n << " elements are sorted in " << setprecision(15) << fixed << sortedTime << " second(s)\n";
	cout << "Reverse " << n << " elements are sorted in " << setprecision(15) << fixed << reverseTime << " second(s)\n";
	cout << "NearlySorted " << n << " elements are sorted in " << setprecision(15) << fixed << nearlySortedTime << " second(s)\n";

	//for (int i = 0; i < n; i++)
	//	cout << a[i] << endl;

	delete[] a;
	delete[] b;
	delete[] c;
	delete[] d;

	return 0;
}