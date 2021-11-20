#include <iostream>
#include <time.h>
#include "GenerateData.h"
using namespace std;



void insertionSort_Com(int a[], int n, unsigned long long& count_com)
{
    count_com = 0;
    int key, j;
    for (int i = 1; ++count_com && i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while ((++count_com && j >= 0) && (++count_com && a[j] > key))
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void merge_com(int a[], int left, int mid, int right, unsigned long long& count_com)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* LEFT = new int[n1];
    int* RIGHT = new int[n2];

    for (i = 0; ++count_com && i < n1; i++)
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
    while ((++count_com && i < n1) && (++count_com && j < n2))
    {
        if (++count_com && LEFT[i] <= RIGHT[j])
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
    while (++count_com && i < n1)
    {
        a[k] = LEFT[i];
        i++;
        k++;
    }
    while (++count_com && j < n2)
    {
        a[k] = RIGHT[j];
        j++;
        k++;
    }
}

void mergeSort_com(int a[], int left, int right, unsigned long long& count_com)
{
    if (++count_com && left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort_com(a, left, mid, count_com);
        mergeSort_com(a, mid + 1, right, count_com);

        merge_com(a, left, mid, right, count_com);
    }
}

void MenuRunTime(int a[], int n, int sort, unsigned long long& count_com)
{
    count_com = 0;
    switch (sort)
    {
    case 2:	//Selection sort
        cout << "Selection Sort: ";
        break;
    case 1:	// Insertion Sort
        cout << "Insertion Sort: ";
        insertionSort_Com(a, n, count_com);
        break;
    case 0:	// Megre sort
        cout << "Merge Sort: ";
        mergeSort_com(a, 0, n - 1, count_com);
        break;
    case 3:	// Heap Sort
        cout << "Heap Sort: ";
        break;
    default:
        printf("Error: unknown data type!\n");
    }
}
int Comparions()
{
    int DataSize[5] = { 30000, 50000, 100000, 300000, 500000 };
    string DataOrder[] = { "Randomized data", "Sorted data",  "Reverse sorted data", "Nearly sorted data" };
    for (int i = 0; i < 4; i++)
    {
        cout << "______________" << DataOrder[i] << "____________________" << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "Data size: " << DataSize[j] << endl;
            int Size = DataSize[j];
            int* a = new int[Size];
            GenerateData(a, Size, i);
            for (int k = 0; k < 2; k++)
            {
                int* a2 = new int[Size];
                copyArray(a, a2, Size);
                unsigned long long count_com = 0;
                MenuRunTime(a2, Size, k, count_com);

                cout << count_com << endl;
            }
            cout << "++++++++++++++++++++++++++++" << endl;
        }
        cout << "===================================" << endl << endl;
    }
    return 0;
}