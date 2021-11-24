#include "Header.h"

void swap1(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// pick_sort(): 0. Selection sort  1. Heap sort  2. Bubble sort  3. Insertion sort
//  4. Radix sort  5. Shakser sort 6. Merge sort  7. Quick sort
void pick_sort_count(int* arr, int size, long long int& count_cmp, int index)
{
	switch (index)
	{
	case(0):
	{
		selection_sort_count(arr, size, count_cmp);
		break;
	}
	case(1):
	{
		heap_sort_count(arr, size, count_cmp);
		break;
	}
	case(2):
	{
		bubble_sort_count(arr, size, count_cmp);
		break;
	}
	case(3):
	{
		insertion_sort_count(arr, size, count_cmp);
		break;
	}
	case(4):
	{
		radix_sort_count(arr, size, count_cmp);
		break;
	}
	case(5):
	{
		shaker_sort_count(arr, size, count_cmp);
		break;
	}
	case(6):
	{
		merge_sort_count(arr, 0, size - 1, count_cmp);
		break;
	}
	case(7):
	{
		quick_sort_count(arr, 0, size - 1, count_cmp);
		break;
	}
	default:
	{
		cout << "Index is out of range!" << endl;
	}
	}
}
void pickSort(int* arr, int size, int index)
{
	switch (index)
	{
	case(0):
	{
		selectionSort(arr, size);
		break;
	}
	case(1):
	{
		heapSort(arr, size);
		break;
	}
	case(2):
	{
		bubbleSort(arr, size);
		break;
	}
	case(3):
	{
		insertionSort(arr, size);
		break;
	}
	case(4):
	{
		radixSort(arr, size);
		break;
	}
	case(5):
	{
		shakerSort(arr, size);
		break;
	}
	case(6):
	{
		mergeSort(arr, 0, size - 1);
		break;
	}
	case(7):
	{
		quickSort(arr, 0, size - 1);
		break;
	}
	default:
	{
		cout << "Index is out of range!" << endl;
	}
	}
}

void copyArray(int* arrA, int*& arrB, int size)
{
	for (int i = 0; i < size; i++)
	{
		arrB[i] = arrA[i];
	}
}
// Vi du cho runSort()
void run_Selection(int* arr, int size)
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
void run_BubbleSort(int* arr, int size)
{
	long long int count_cmp = 0;
	auto start = high_resolution_clock::now();
	bubble_sort_count(arr, size, count_cmp);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);

	cout << "BUBBLE SORT: \n";
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
}
//
void runSort(int arr[], int size, int index)
{
	// do chạy sort 2 lần nên cần cope arr sang mảng khác
	int* arrB = new int[size];
	copyArray(arr, arrB, size);
	// Đếm thời gian sort
	auto start = high_resolution_clock::now();
	pickSort(arrB, size, index); 
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	// Đếm số lần so sánh, tách riêng ra vì đếm so sánh gây ảnh hưởng lớn tới thời gian sort
	copyArray(arr, arrB, size);
	long long int count_cmp = 0;
	pick_sort_count(arrB, size, count_cmp, index);
	delete[] arrB;

	string sortName[8] = {"SELECTION SORT", "HEAP SORT", "BUBBLE SORT", "INSERTION SORT", "RADIX SORT", "SHAKER SORT", "MERGE SORT", "QUICK SORT"};
	cout << sortName[index] << endl;
	cout << "Time taken: " << duration.count() << " miliseconds (without count comparisons)" << endl;
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
		file << sortName[index] << endl;
		file << duration.count() << " miliseconds (without count comparisons)" << endl;
		file << count_cmp << " times" << endl << endl;
	}
}

void experiments()
{
	fstream file;
	file.open("Chart.txt", ios::app);
	int size[6] = { 10000,  30000,  50000,  100000,  300000,  500000 };
	int index = 0;
	long long int count_cmp = 0;
	string name[4] = { "Sorted data", "Nearly sorted data", "Reserve sorted data", "Randomized data" };
	for (int i = 0; i < 4; i++)
	{
		// 0: sorted data	1: nearly sorted data	2: reserve sorted data	3: randomized data
		cout << "----------- Type: " << name[i] << "-----------" << endl;
		
		for (int j = 0; j < 3; j++)
		{
			cout << "-----------" << "Size: " << size[j] << endl;
			int* arrA = new int[size[j]];
			index = 0;

			GenerateData(arrA, size[j], i);

			file.seekp(file.eof());
			file << name[i] << " | size: " << size[j] << endl;

			// * Quick sort is currently disable! in pick_sort()
			for (int a = 0; a < 8; a++)
			{
				runSort(arrA, size[j], index++);
			}
			file << "-------------------" << endl;
			delete[] arrA;
		}
		cout << endl;
	}
}