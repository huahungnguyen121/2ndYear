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
	int a[30000];
	int b[30000];
	int c[30000];
	int d[30000];

	int n = 30000;

	GenerateData(a, n, 0);
	GenerateData(b, n, 1);
	GenerateData(c, n, 2);
	GenerateData(d, n, 3);

	float ranTime = insertionSort(a, n);
	float sortedTime = insertionSort(b, n);
	float reverseTime = insertionSort(c, n);
	float nearlySortedTime = insertionSort(d, n);


	cout << "Random " << n << " element are sorted in " << ranTime << " second(s)\n";
	cout << "Sorted " << n << " element are sorted in " << sortedTime << " second(s)\n";
	cout << "Reverse " << n << " element are sorted in " << reverseTime << " second(s)\n";
	cout << "NearlySorted " << n << " element are sorted in " << nearlySortedTime << " second(s)\n";

	//for (int i = 0; i < n; i++)
	//	cout << a[i] << endl;

	return 0;
}