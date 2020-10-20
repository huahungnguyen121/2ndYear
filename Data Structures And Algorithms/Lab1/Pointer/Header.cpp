#include "Header.h"

int BinarySearch(int* a, int n, int key)
{
    int left = 0;
    int right = n - 1;
    
    while (left < right)
    {
        int temp = (left + right) / 2;

        if (key < a[temp])
        {
            right = temp - 1;
        }
        else if (key > a[temp])
        {
            left = temp + 1;
        }
        else
            return temp;
    }

    if (left == right)
        return (a[left] == key) ? left : -1;
    return -1;
}

int RecursiveBinarySearch(int* a, int left, int right, int key)
{   
    if (left > right)
        return -1;

    if (left == right)
        return (a[left] == key) ? left : -1;
    
    int mid = (left + right) / 2;

    if (key < a[mid])
    {
        return RecursiveBinarySearch(a, left, mid - 1, key);
    }

    if (key > a[mid])
    {
        return RecursiveBinarySearch(a, mid + 1, right, key);
    }

    if (key == a[mid])
        return mid;
}