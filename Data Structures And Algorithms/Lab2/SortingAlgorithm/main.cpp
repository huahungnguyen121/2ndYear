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
	//int n = 300000;

	//int *a = new int[n];
	//int *b = new int[n];
	//int *c = new int[n];
	//int *d = new int[n];
	int e[100];

	//GenerateData(a, n, 0);
	//GenerateData(b, n, 1);
	//GenerateData(c, n, 2);
	//GenerateData(d, n, 3);
	GenerateData(e, 100, 0);

	for (int i = 0; i < 10; i++)
		cout << e[i] << endl;

	cout << endl;

	//float ranTime = quickSort(a, 0, n - 1);
	//float sortedTime = quickSort(b, 0, n - 1);
	//float reverseTime = quickSort(c, 0, n - 1);
	//float nearlySortedTime = quickSort(d, 0, n - 1);

	radixSort(e, 100);


	//cout << "Random " << n << " element are sorted in " << ranTime << " second(s)\n";
	//cout << "Sorted " << n << " element are sorted in " << sortedTime << " second(s)\n";
	//cout << "Reverse " << n << " element are sorted in " << reverseTime << " second(s)\n";
	//cout << "NearlySorted " << n << " element are sorted in " << nearlySortedTime << " second(s)\n";

	for (int i = 0; i < 100; i++)
		cout << e[i] << endl;

	//delete[] a;
	//delete[] b;
	//delete[] c;
	//delete[] d;

	return 0;
}