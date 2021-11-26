#include "Header.h"

void selectionSort(int* arr, int n)
{
	// sap xep tang dan
	int index;
	bool checkAscending = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			checkAscending = false; // Kiểm tra mảng có thứ tự tăng dần hay không
			break;
		}
	}
	if (checkAscending == false)
	{
		for (int i = 0; i < n; i++)
		{
			index = 0; // Xét tại vị trí đầu tiên
			for (int j = 1; j < n - i; j++)
			{
				if (arr[index] < arr[j])
				{
					index = j; // Tìm giá trị lớn nhất trong khoảng từ 0 đến n - i
				}
			}
			HoanVi(arr[index], arr[n - i - 1]); // Hoán đổi giá trị lớn nhất vừa tìm được cho phần tử đứng trước vùng đã sắp xếp
		}
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
	for (int i = 1; i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while (a[k] > key && k >= 0)
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
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
				HoanVi(arr[j], arr[j + 1]);
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
void shellSort(int a[], int n)
{
	for (int interval = n / 2; interval > 0; interval /= 2)
	{
		for (int i = interval; i < n; i++)
		{
			int temp = a[i];
			int j = i;
			for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
				a[j] = a[j - interval];
			a[j] = temp;
		}
	}
}
//
void countingSort(int input[], int n)
{
	int* output = new int[n]; // The output will have sorted input array
	int max = input[0];
	int min = input[0];

	for (int i = 1; i < n; i++)
	{
		if (input[i] > max)
			max = input[i]; // Maximum value in array
		else if (input[i] < min)
			min = input[i]; // Minimum value in array
	}
	int k = max - min + 1; // Size of count array
	int* count_array = new int[k]; // Create a count_array to store count of each individual input value
	fill_n(count_array, k, 0); // Initialize count_array elements as zero
	for (int i = 0; i < n; i++)
		count_array[input[i] - min]++; // Store count of each individual input value
	/* Change count_array so that count_array now contains actual
	 position of input values in output array */
	for (int i = 1; i < k; i++)
		count_array[i] += count_array[i - 1];
	// Populate output array using count_array and input array
	for (int i = 0; i < n; i++)
	{
		output[count_array[input[i] - min] - 1] = input[i];
		count_array[input[i] - min]--;
	}
	for (int i = 0; i < n; i++)
	{
		input[i] = output[i]; // Copy the output array to input, so that input now contains sorted value
	}
}
//
void flashSort(int a[], int n)
{
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}
	if (a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];
	HoanVi(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertionSort(a, n);
}