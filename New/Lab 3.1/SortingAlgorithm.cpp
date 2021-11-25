#include "Header.h"

void selectionSort(int* arr, int n)
{
	// sap xep tang dan
	int largeNumber, temp, index;
	for (int i = 0; i < n; i++)
	{
		index = 0; // dat lai vi tri tai dau mang
		largeNumber = arr[0];
		for (int j = 1; j < n - i; j++)
		{
			if (largeNumber < arr[j]) // tim phan tu lon nhat trong vi tri tu 0 den n - i
			{
				largeNumber = arr[j];
				index = j;
			}
		}
		temp = arr[n - 1 - i]; // hoan doi vi tri phan tu lon nhat vua tim duoc cho phan tu thu n - 1 - i
		arr[n - 1 - i] = arr[index];
		arr[index] = temp;
	}
}
//
void heapRebuild(int index, int* arr, int n)
{
	// sap xep theo max-heap
	bool isHeap = false;
	int k = index;
	while (isHeap == false && 2 * k + 1 < n)
	{
		int j = 2 * k + 1;
		if (j < n - 1) // kiem tra co du 2 phan tu (o cuoi mang)
		{
			if (arr[j] < arr[j + 1]) // tim phan tu nao lon hon
			{
				j++;
			}
		}
		if (arr[k] >= arr[j])// kiem tra co phai la heap hay khong
		{
			isHeap = true;
		}
		else
		{
			int temp = arr[j]; // hoan doi vi tri cua 2 phan tu do
			arr[j] = arr[k];
			arr[k] = temp;
			k = j; // xet tiep phan tu tai j xem thu co lam thay doi cau truc heap hay khong
		}
	}
}
void heapConstruct(int* arr, int n)
{

	int index = (n - 1) / 2;
	while (index >= 0)
	{
		heapRebuild(index, arr, n); // tao lai heap
		index = index - 1;
	}
}
void heapSort(int* arr, int n)
{
	// tu slide
	// sap xep tang dan
	heapConstruct(arr, n); // tao cau truc heap cho mang, phan tu dau cua max-heap luon luon lon nhat
	int r = n - 1;
	while (r > 0)
	{
		int temp = arr[0]; // hoan doi vi tri cua phan tu lon nhat cua vung chua sap xep cho phan tu o truoc vung da duoc sap xep
		arr[0] = arr[r];
		arr[r] = temp;
		heapRebuild(0, arr, r); // la cau truc heap nen khi thay doi phan tu dau tien thi chi thay doi 1 phan cua truc heap
		r = r - 1;
	}
}
//
void merge(int a[], int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* LEFT = new int[n1];
	int* RIGHT = new int[n2];

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
void mergeSort(int a[], int left, int right) // left: nho nhat, right: lon nhat, khi bat dau chay cho left = 0, right = n - 1
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);

		merge(a, left, mid, right);
	}
}
//
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
//
void bubbleSort(int arr[], int n)
{
	int i, j;
	bool haveSwap = false;
	for (i = 0; i < n - 1; i++) {
		//  the last element have sorted
		haveSwap = false;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
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
//
int partition(int a[], int first, int last)
{
	int pivot = a[(first + last) / 2];
	int i = first;
	int j = last;
	int tmp;
	while (i <= j)
	{
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j) {
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}
	return i;
}
void quickSort(int a[], int first, int last)
{
	int index = partition(a, first, last);
	if (first < index - 1)
		quickSort(a, first, index - 1);
	if (index < last)
		quickSort(a, index, last);
}
//
void radixSort(int a[], int n)
{
	int* b = new int[n];
	int k = a[0], exp = 1;

	for (int i = 0; i < n; i++)// Tim so lon nhat
	{
		if (a[i] > k)
			k = a[i];
	}
	while (k / exp > 0)
	{
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++) {
			bucket[a[i] / exp % 10]++;
		}
		for (int i = 1; i < 10; i++)
		{
			bucket[i] += bucket[i - 1];
		}
		for (int i = n - 1; i >= 0; i--)
		{
			b[--bucket[a[i] / exp % 10]] = a[i];
		}
		for (int i = 0; i < n; i++) {
			a[i] = b[i];
		}
		exp *= 10;
	}
}
//
void shakerSort(int a[], int n)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (a[i] > a[i + 1])
			{
				HoanVi(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int j = Right; j > Left; j--)
		{
			if (a[j] < a[j - 1])
			{
				HoanVi(a[j], a[j - 1]);
				k = j;
			}
		}
		Left = k;
	}
}
//
void MenuRunTime(int a[], int n, int sort)
{
	switch (sort)
	{
	case 0:	//Selection sort
		cout << "Selection Sort: ";
		selectionSort(a, n);
		break;
	case 1:	// Insertion Sort
		cout << "Insertion Sort: ";
		insertionSort(a, n);
		break;
	case 2:	// Megre sort
		cout << "Merge Sort: ";
		mergeSort(a, 0, n - 1);
		break;
	case 3:	// Heap Sort
		cout << "Heap Sort: ";
		heapSort(a, n);
		break;
	case 4:
		cout << "Bubble Sort: ";
		bubbleSort(a, n);
		break;
	case 5:
		cout << "Quick Sort: ";
		quickSort(a, 0, n);
		break;
	case 6:
		cout << "Radix Sort: ";
		radixSort(a, n);
		break;
	case 7:
		cout << "Shanker Sort: ";
		shakerSort(a, n);
		break;
	case 8:
		cout << "Shell Sort: ";
		break;
	case 9:
		cout << "Counting Sort: ";
		
		break;
	case 10:
		cout << "Flash Sort: ";

		break;
	default:
		printf("Error: unknown data type!\n");
	}
}