#include "Header.h"

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    
    int temp = a % b;
    return GCD(b, temp);
}

bool isPalindrome(int a[], int n)
{
    
}
