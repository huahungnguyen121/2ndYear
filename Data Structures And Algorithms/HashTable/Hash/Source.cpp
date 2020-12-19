#include <iostream>

using namespace std;

int hashFunc(int k, int m) {
    return k % m;
}

bool isFull(int* a, int m) {
	for (int i = 0; i < m; i++)
		if (a[i] == -1)
			return false;
	return true;
}

void linearProbing(int* a, int m, int k) {
    int i = hashFunc(k, m);
    if (a[i] == -1) {
        a[i] = k;
        return;
    }
    else {
		int j = 0;
        while (true) {
            i++;
			j++;
			if (i >= m - 1)
				i = i % m;
            if (a[i] == -1) {
                a[i] = k;
                return;
            }
			if (j == m - 1)
				return;
        }
    }
}

void quadraticProbing(int* a, int m, int k) {
	int i = hashFunc(k, m);
	if (a[i] == -1) {
		a[i] = k;
		return;
	}
	else {
		int j = 1;
		while (true) {
			if (isFull(a, m))
				return;
			int index = i + j * j;
            j++;
			if (index >= m - 1)
				index = index % m;
			if (a[index] == -1) {
				a[index] = k;
				return;
			}
		}
	}
}

int main() {

    int a[17];

    for (int i = 0; i < 17; i++)
        a[i] = -1;

   /* linearProbing(a, 17, 10);
    linearProbing(a, 17, 22);
    linearProbing(a, 17, 31);
    linearProbing(a, 17, 4);
    linearProbing(a, 17, 47);
    linearProbing(a, 17, 44);
    linearProbing(a, 17, 39);
    linearProbing(a, 17, 65);
    linearProbing(a, 17, 73);
    linearProbing(a, 17, 55);*/

	quadraticProbing(a, 17, 10);
	quadraticProbing(a, 17, 22);
	quadraticProbing(a, 17, 31);
	quadraticProbing(a, 17, 4);
	quadraticProbing(a, 17, 47);
	quadraticProbing(a, 17, 44);
	quadraticProbing(a, 17, 39);
	quadraticProbing(a, 17, 65);
	quadraticProbing(a, 17, 73);
	quadraticProbing(a, 17, 55);

    for (int i = 0; i < 17; i++)
        cout << a[i] << " ";

    return 0;
}