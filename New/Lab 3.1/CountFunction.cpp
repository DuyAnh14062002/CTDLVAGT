#include "Header.h"

void selection_sort_count(int* arr, int n, unsigned long long& count_cmp)
{
	// sap xep tang dan
	count_cmp = 0;
	int index;
	bool checkAscending = true;
	for (int i = 0;++count_cmp && i < n - 1; i++)
	{
		if (++count_cmp && arr[i] > arr[i + 1])
		{
			checkAscending = false;
			break;
		}
	}
	if (++count_cmp && checkAscending == false)
	{
		for (int i = 0;++count_cmp && i < n; i++)
		{
			index = 0;
			for (int j = 1;++count_cmp && j < n - i; j++)
			{
				if (++count_cmp && arr[index] < arr[j])
				{
					index = j;
				}
			}
			HoanVi(arr[index], arr[n - i - 1]);
		}
	}
}
//
void heap_rebuild_count(int index, int* arr, int n, unsigned long long & count_cmp)
{
	// sap xep theo max-heap
	bool isHeap = false;
	int k = index;
	while (++count_cmp && isHeap == false && 2 * k + 1 < n)
	{
		int j = 2 * k + 1;
		if (++count_cmp && j < n - 1) // kiem tra co du 2 phan tu (o cuoi mang)
		{
			if (++count_cmp && arr[j] < arr[j + 1]) // tim phan tu nao lon hon
			{
				j++;
			}
		}
		if (++count_cmp && arr[k] >= arr[j])// kiem tra co phai la heap hay khong
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
void heap_construct_count(int* arr, int n, unsigned long long & count_cmp)
{

	int index = (n - 1) / 2;
	while (++count_cmp && index >= 0)
	{
		heap_rebuild_count(index, arr, n, count_cmp); // tao lai heap
		index = index - 1;
	}
}
void heap_sort_count(int* arr, int n, unsigned long long & count_cmp)

{
	// tu slide
	// sap xep tang dan
	count_cmp = 0;
	heap_construct_count(arr, n, count_cmp); // tao cau truc heap cho mang, phan tu dau cua max-heap luon luon lon nhat
	int r = n - 1;
	while (++count_cmp && r > 0)
	{
		int temp = arr[0];  // hoan doi vi tri cua phan tu lon nhat cua vung chua sap xep cho phan tu o truoc vung da duoc sap xep
		arr[0] = arr[r];
		arr[r] = temp;
		heap_rebuild_count(0, arr, r, count_cmp); // la cau truc heap nen khi thay doi phan tu dau tien thi chi thay 1 phan cua truc heap
		r = r - 1;
	}
}
//
void bubble_sort_count(int arr[], int n, unsigned long long & count_cmp)
{
	int i, j;
	bool haveSwap = false;
	for (i = 0; ++count_cmp && i < n - 1; i++) {
		//  the last element have sorted
		haveSwap = false;
		for (j = 0; ++count_cmp && j < n - i - 1; j++) {
			if (++count_cmp && arr[j] > arr[j + 1]) {
				HoanVi(arr[j], arr[j + 1]);
				haveSwap = true; //Check if this iteration has swap
			}
		}
		//If no swap is performed = > sorted array.No need to repeat
		if (++count_cmp && haveSwap == false) {
			break;
		}
	}
}
//
void insertion_sort_count(int a[], int n, unsigned long long & count_cmp)
{
	for (int i = 1; ++count_cmp && i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while ((++count_cmp && a[k] > key) && (++count_cmp && k >= 0))
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}
//
void radix_sort_count(int a[], int n, unsigned long long & count_cmp)

{
	int* b = new int[n];
	int k = a[0], exp = 1;

	for (int i = 0; ++count_cmp && i < n; i++)// Tim so lon nhat
	{
		if (++count_cmp && a[i] > k)
			k = a[i];
	}
	while (++count_cmp && k / exp > 0)
	{
		int bucket[10] = { 0 };
		for (int i = 0; ++count_cmp && i < n; i++) {
			bucket[a[i] / exp % 10]++;
		}
		for (int i = 1; ++count_cmp && i < 10; i++)
		{
			bucket[i] += bucket[i - 1];
		}
		for (int i = n - 1; ++count_cmp && i >= 0; i--)
		{
			b[--bucket[a[i] / exp % 10]] = a[i];
		}
		for (int i = 0; ++count_cmp && i < n; i++) {
			a[i] = b[i];
		}
		exp *= 10;
	}
}
//
void shaker_sort_count(int a[], int n, unsigned long long & count_cmp)

{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (++count_cmp&& Left < Right)
	{
		for (int i = Left; ++count_cmp && i < Right; i++)
		{
			if (++count_cmp && a[i] > a[i + 1])
			{
				HoanVi(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int j = Right; ++count_cmp && j > Left; j--)
		{
			if (++count_cmp && a[j] < a[j - 1])
			{
				HoanVi(a[j], a[j - 1]);
				k = j;
			}
		}
		Left = k;
	}
}
//
void merge_count(int a[], int left, int mid, int right, unsigned long long & count_cmp)

{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* LEFT = new int[n1];
	int* RIGHT = new int[n2];

	for (i = 0; ++count_cmp && i < n1; i++)
	{
		LEFT[i] = a[left + i];
	}
	for (j = 0; ++count_cmp && j < n2; j++)
	{
		RIGHT[j] = a[mid + 1 + j];
	}
	i = 0;
	j = 0;
	k = left;
	while (++count_cmp && i < n1 && j < n2)
	{
		if (++count_cmp && LEFT[i] <= RIGHT[j])
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
	while (++count_cmp && i < n1)
	{
		a[k] = LEFT[i];
		i++;
		k++;
	}
	while (++count_cmp && j < n2)
	{
		a[k] = RIGHT[j];
		j++;
		k++;
	}
}
void merge_sort_count(int a[], int left, int right, unsigned long long & count_cmp)
{
	if (++count_cmp && left < right)
	{
		int mid = left + (right - left) / 2;

		merge_sort_count(a, left, mid, count_cmp);
		merge_sort_count(a, mid + 1, right, count_cmp);

		merge_count(a, left, mid, right, count_cmp);
	}
}
//
int partition_count(int a[], int first, int last, unsigned long long & count_cmp)
{
	int pivot = a[(first + last) / 2];
	int i = first;
	int j = last;
	int tmp;
	while (++count_cmp && i <= j)
	{
		while (++count_cmp && a[i] < pivot)
			i++;
		while (++count_cmp && a[j] > pivot)
			j--;
		if (++count_cmp && i <= j) {
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}
	return i;
}
void quick_sort_count(int a[], int first, int last, unsigned long long & count_cmp)
{
	int index = partition_count(a, first, last, count_cmp);
	if (++count_cmp && first < index - 1)
		quick_sort_count(a, first, index - 1, count_cmp);
	if (++count_cmp && index < last)
		quick_sort_count(a, index, last, count_cmp);
}
//
void shell_sort_count(int a[], int n, unsigned long long& count_cmp)
{
	count_cmp = 0;
	for (int interval = n / 2; ++count_cmp && interval > 0; interval /= 2)
	{
		for (int i = interval; ++count_cmp && i < n; i++)
		{
			int temp = a[i];
			int j = i;
			for (j = i; ++count_cmp && j >= interval && ++count_cmp && a[j - interval] > temp; j -= interval)
				a[j] = a[j - interval];
			a[j] = temp;
		}
	}
}
//
void counting_sort_count(int input[], int n, unsigned long long& count_cmp)
{
	count_cmp = 0;
	int* output = new int[n]; // The output will have sorted input array
	int max = input[0];
	int min = input[0];

	for (int i = 1; ++count_cmp && i < n; i++)
	{
		if (++count_cmp && input[i] > max)
			max = input[i]; // Maximum value in array
		else if (++count_cmp && input[i] < min)
			min = input[i]; // Minimum value in array
	}
	int k = max - min + 1; // Size of count array
	int* count_array = new int[k]; // Create a count_array to store count of each individual input value
	fill_n(count_array, k, 0); // Initialize count_array elements as zero
	for (int i = 0; ++count_cmp && i < n; i++)
		count_array[input[i] - min]++; // Store count of each individual input value
	/* Change count_array so that count_array now contains actual
	 position of input values in output array */
	for (int i = 1; ++count_cmp && i < k; i++)
		count_array[i] += count_array[i - 1];
	// Populate output array using count_array and input array
	for (int i = 0; ++count_cmp && i < n; i++)
	{
		output[count_array[input[i] - min] - 1] = input[i];
		count_array[input[i] - min]--;
	}
	for (int i = 0; ++count_cmp && i < n; i++)
	{
		input[i] = output[i]; // Copy the output array to input, so that input now contains sorted value
	}
}
//
void flash_sort_count(int a[], int n, unsigned long long& count_cmp)
{
	count_cmp = 0;
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; ++count_cmp && i < m; i++)
		l[i] = 0;
	for (int i = 1; ++count_cmp && i < n; i++)
	{
		if (++count_cmp && a[i] < minVal)
			minVal = a[i];
		if (++count_cmp && a[i] > a[max])
			max = i;
	}
	if (++count_cmp && a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; ++count_cmp && i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; ++count_cmp && i < m; i++)
		l[i] += l[i - 1];
	HoanVi(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (++count_cmp && nmove < n - 1)
	{
		while (++count_cmp && j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (++count_cmp && k < 0) break;
		while (++count_cmp && j != l[k])
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