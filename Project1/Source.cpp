#include <iostream>
using namespace std;

void insertionSort(int a[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void mergesort(int a[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* LEFT = new int [n1];
    int *RIGHT = new int [n2];

    for (i = 0; i < n1; i++)
    {
        LEFT[i] = a[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        RIGHT[j] = a[mid + 1 + j];
    }
    i = 0; 
    j = 0; 
    k = left;
    while (i < n1 && j < n2)
    {
        if (LEFT[i] <= RIGHT[j])
        {
            a[k] = LEFT[i];
            i++;
        }
        else
        {
            a[k] = RIGHT[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = LEFT[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = RIGHT[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        mergesort(a, left, mid, right);
    }
}