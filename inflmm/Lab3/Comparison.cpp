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
void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}
void bubbleSort_count(int arr[], int n, unsigned long long& count_cmp)
{
    count_cmp = 0;
    int i, j;
    bool haveSwap = false;
    for (i = 0;++count_cmp && i < n - 1; i++) {
        //  the last element have sorted
        haveSwap = false;
        for (j = 0; ++count_cmp && j < n - i - 1; j++) {
            if (++count_cmp && arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                haveSwap = true; //Check if this iteration has swap
            }
        }
        //If no swap is performed = > sorted array.No need to repeat
        if (haveSwap == false) {
            break;
        }
    }
}
int partition_count(int arr[], int low, int high, unsigned long long& count_cmp)
{
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while (true) {
        while (++count_cmp && left <= right && ++count_cmp && arr[left] < pivot) left++;
        while (++count_cmp && right >= left && ++count_cmp && arr[right] > pivot) right--;
        if (++count_cmp && left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
void quickSort_count(int arr[], int low, int high, unsigned long long& count_cmp)
{
    if (++count_cmp && low < high)
    {
        int pi = partition_count(arr, low, high, count_cmp);
        quickSort_count(arr, low, pi - 1, count_cmp);
        quickSort_count(arr, pi + 1, high, count_cmp);
    }
}
void radixSort_com(int a[], int n, unsigned long long& count_com)
{
    int* b = new int[n];
    int k = a[0], exp = 1;
    for (int i = 0;++count_com&& i < n; i++)// Tim so lon nhat
    {
        if (++count_com && a[i] > k)
            k = a[i];
    }
    while (++count_com && k / exp > 0)
    {
        int bucket[10] = { 0 };
        for (int i = 0; ++count_com && i < n; i++) {
            bucket[a[i] / exp % 10]++;
        }
        for (int i = 1; ++count_com && i < 10; i++)
        {
            bucket[i] += bucket[i - 1];
        }
        for (int i = n - 1; ++count_com && i >= 0; i--)
        {
            b[--bucket[a[i] / exp % 10]] = a[i];
        }
        for (int i = 0; ++count_com && i < n; i++) {
            a[i] = b[i];
        }
        exp *= 10;
    }
}
void shakerSort_com(int a[], int n, unsigned long long& count_com)
{
    int Left = 0;
    int Right = n - 1;
    int k = 0;
    while (++count_com && Left < Right)
    {
        for (int i = Left; ++count_com && i < Right; i++)
        {
            if (++count_com && a[i] > a[i + 1])
            {
                HoanVi(a[i], a[i + 1]);
                k = i;
            }
        }
        Right = k;
        for (int j = Right; ++count_com && j > Left; j--)
        {
            if (++count_com && a[j] < a[j - 1])
            {
                HoanVi(a[j], a[j - 1]);
                k = j;
            }
        }
        Left = k;
    }
}
void MenuComparison(int a[], int n, int sort, unsigned long long& count_com)
{
    count_com = 0;
    switch (sort)
    {
    case 0:	//Selection sort
        cout << "Selection Sort: ";
        break;
    case 1:	// Insertion Sort
        cout << "Insertion Sort: ";
        insertionSort_Com(a, n, count_com);
        break;
    case 2:	// Megre sort
        cout << "Merge Sort: ";
        mergeSort_com(a, 0, n - 1, count_com);
        break;
    case 3:	// Heap Sort
        cout << "Heap Sort: ";
        break;
    case 4:
        cout << "Bubble Sort: ";
        break;
    case 5:
        cout << "Quick Sort: ";
        break;
    case 6:
        cout << "Radix Sort: ";
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