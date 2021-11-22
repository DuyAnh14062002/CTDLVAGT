#include "Header.h"

void selection_sort_count(int* arr, int n, long long int& count_cmp)
{
	// sap xep tang dan
	count_cmp = 0;
	int largeNumber, temp, index;
	for (int i = 0; ++count_cmp && i < n; i++)
	{
		index = 0; // dat lai vi tri tai dau mang
		largeNumber = arr[0];
		count_cmp++;
		for (int j = 1; ++count_cmp && j < n - i; j++)
		{
			if (++count_cmp && largeNumber < arr[j]) // tim phan tu lon nhat trong vi tri tu 0 den n - i
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
void heap_rebuild_count(int index, int* arr, int n, long long int& count_cmp)
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
void heap_construct_count(int* arr, int n, long long int& count_cmp)
{

	int index = (n - 1) / 2;
	while (++count_cmp && index >= 0)
	{
		heap_rebuild_count(index, arr, n, count_cmp); // tao lai heap
		index = index - 1;
	}
}
void heap_sort_count(int* arr, int n, long long int& count_cmp)

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
void bubble_sort_count(int arr[], int n, long long int& count_cmp)
{
	int i, j;
	bool haveSwap = false;
	for (i = 0; ++count_cmp && i < n - 1; i++) {
		//  the last element have sorted
		haveSwap = false;
		for (j = 0; ++count_cmp && j < n - i - 1; j++) {
			if (++count_cmp && arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
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
void insertion_sort_count(int a[], int n, long long int& count_cmp)

{
	int i, key, j;
	for (i = 1; ++count_cmp && i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (++count_cmp && j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}
//
void radix_sort_count(int a[], int n, long long int& count_cmp)

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
void shaker_sort_count(int a[], int n, long long int& count_cmp)

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
void merge_count(int a[], int left, int mid, int right, long long int& count_cmp)

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
void merge_sort_count(int a[], int left, int right, long long int& count_cmp)
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
int partition_count(int arr[], int low, int high, long long int& count_cmp)

{
	int pivot = arr[high];    // pivot
	int left = low;
	int right = high - 1;
	while (++count_cmp && true) {
		while (++count_cmp && left <= right && arr[left] < pivot) left++;
		while (++count_cmp && right >= left && arr[right] > pivot) right--;
		if (++count_cmp && left >= right) break;
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
	swap(arr[left], arr[high]);
	return left;
}
void quick_sort_count(int arr[], int low, int high, long long int& count_cmp)
{
	if (++count_cmp && low < high)
	{
		int pi = partition_count(arr, low, high, count_cmp);
		quick_sort_count(arr, low, pi - 1, count_cmp);
		quick_sort_count(arr, pi + 1, high, count_cmp);
	}
}