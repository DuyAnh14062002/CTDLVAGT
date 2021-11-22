#include <iostream>
#include <chrono>
#include <fstream>
#include <cmath>
#include <time.h>
#include <fstream>

using namespace std;
using namespace std::chrono;

template <class T>
void HoanVi(T& a, T& b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

void selection_sort(int* arr, int n)
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
void heap_sort(int* arr, int n)
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
		heapRebuild(0, arr, r); // la cau truc heap nen khi thay doi phan tu dau tien thi chi thay 1 phan cua truc heap
		r = r - 1;
	}
}

void selection_sort_count(int* arr, int n, long long int& count_cmp)
{
	// sap xep tang dan
	count_cmp = 0;
	int largeNumber, temp, index;
	for (int i = 0;++count_cmp && i < n; i++)
	{
		index = 0; // dat lai vi tri tai dau mang
		largeNumber = arr[0];
		count_cmp++;
		for (int j = 1;++count_cmp && j < n - i; j++)
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
void heapRebuild_count(int index, int* arr, int n, long long int& count_cmp)
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
void heapConstruct_count(int* arr, int n, long long int& count_cmp)
{

	int index = (n - 1) / 2;
	while (++count_cmp && index >= 0)
	{
		heapRebuild_count(index, arr, n, count_cmp); // tao lai heap
		index = index - 1;
	}
}
void heap_sort_count(int* arr, int n, long long int& count_cmp)

{
	// tu slide
	// sap xep tang dan
	count_cmp = 0;
	heapConstruct_count(arr, n, count_cmp); // tao cau truc heap cho mang, phan tu dau cua max-heap luon luon lon nhat
	int r = n - 1;
	while (++count_cmp && r > 0)
	{
		int temp = arr[0];  // hoan doi vi tri cua phan tu lon nhat cua vung chua sap xep cho phan tu o truoc vung da duoc sap xep
		arr[0] = arr[r];
		arr[r] = temp;
		heapRebuild_count(0, arr, r, count_cmp); // la cau truc heap nen khi thay doi phan tu dau tien thi chi thay 1 phan cua truc heap
		r = r - 1;
	}
}
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
void radixSort_com(int a[], int n, unsigned long long& count_com)
{
	int* b = new int[n];
	int k = a[0], exp = 1;
	for (int i = 0; ++count_com && i < n; i++)// Tim so lon nhat
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
	while (++count_com&& Left < Right)
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
void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}
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
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot
	int left = low;
	int right = high - 1;
	while (true) {
		while (left <= right && arr[left] < pivot) left++;
		while (right >= left && arr[right] > pivot) right--;
		if (left >= right) break;
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
	swap(arr[left], arr[high]);
	return left;
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
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
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
void copyArray(int* arrA, int*& arrB, int size)
{
	for (int i = 0; i < size; i++)
	{
		arrB[i] = arrA[i];
	}
}

void run_Selection(int *arr, int size)
{
	long long int count_cmp = 0;
	auto start = high_resolution_clock::now();
	selection_sort_count(arr, size, count_cmp);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);

	cout << "SELECTION SORT: \n";
	cout << "Time taken: " << duration.count() << " miliseconds" << endl;
	cout << "Number of comparisons: " << count_cmp << endl << endl;
	fstream file;
	file.open("Chart.txt", ios::app);
	if (!file.is_open())
	{
		cout << "Can not open file.\n";
	}
	else
	{
		file.seekp(file.eof());
		file << duration.count() << " miliseconds" << endl;
		file << count_cmp << " times" << endl << endl;
	}
	//file.close();
}

void run_Heap(int* arr, int size)
{
	long long int count_cmp = 0;
	auto start = high_resolution_clock::now();
	heap_sort_count(arr, size, count_cmp);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);

	cout << "HEAP SORT: \n";
	cout << "Time taken: " << duration.count() << " miliseconds" << endl;
	cout << "Number of comparisons: " << count_cmp << endl << endl;
	fstream file;
	file.open("Chart.txt", ios::app);
	if (!file.is_open())
	{
		cout << "Can not open file.\n";
	}
	else
	{
		file.seekp(file.eof());
		file << duration.count() << " miliseconds" << endl;
		file << count_cmp << " times" << endl << endl;
	}
	//file.close();
}

void experiments()
{
	fstream file;
	file.open("Chart.txt", ios::app);
	int size[6] = { 10000,  30000,  50000,  100000,  300000,  500000 };
	long long int count_cmp = 0;
	string name[4] = {"Sorted data", "Nearly sorted data", "Reserve sorted data", "Randomized data"};
	for (int i = 0; i < 1; i++)
	{
		// 1: sorted data	2: nearly sorted data	3: reserve sorted data	4: randomized data
		cout << "----------- Type: " << name[i] << "-----------" << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << "-----------" <<  "Size: " << size[j] << endl;
			int* arrA = new int[size[j]];
			int* arrB = new int[size[j]];
			
			GenerateData(arrA, size[j], i);

			// Selection Sort
			copyArray(arrA, arrB, size[j]);
			file.seekp(file.eof());
			file << name[i] << " | size: " << size[j] << endl;
			run_Selection(arrB, size[j]);
			


			// Heap Sort
			copyArray(arrA, arrB, size[j]);
			file.seekp(file.eof());
			file << name[i] << " | size: " << size[j] << endl;
			run_Heap(arrB, size[j]);
			
		}
		cout << endl;
	}
}

int main()
{
	//int arr[10] = { 4,8,5,0,2,7,11,9,3,10 };
	int n = 10, count_cmp = 0;
	//selection_sort(arr, n);
	/*heapConstruct(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	heap_sort(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}*/
	fstream file;
	file.open("Chart.txt", ios::out);
	
	experiments();
	file.close();
	return 0;
}