#include "Header.h"

// pick_sort(): 0. Selection sort  1. Heap sort  2. Bubble sort  3. Insertion sort
//  4. Radix sort  5. Shakser sort 6. Merge sort  7. Quick sort
void pick_sort(int* arr, int size, long long int& count_cmp, int index)
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
		//quick_sort_count(arr, , , count_cmp);
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
	long long int count_cmp = 0;
	auto start = high_resolution_clock::now();
	pick_sort(arr, size, count_cmp, index);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);


	string sortName[8] = {"SELECTION SORT", "HEAP SORT", "BUBBLE SORT", "INSERTION SORT", "RADIX SORT", "SHAKER SORT", "MERGE SORT", "QUICK SORT"};
	cout << sortName[index] << endl;
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
		file << sortName[index] << endl;
		file << duration.count() << " miliseconds" << endl;
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
		
		for (int j = 0; j < 2; j++)
		{
			cout << "-----------" << "Size: " << size[j] << endl;
			int* arrA = new int[size[j]];
			int* arrB = new int[size[j]];
			index = 0;

			GenerateData(arrA, size[j], i);

			file.seekp(file.eof());
			file << name[i] << " | size: " << size[j] << endl;

			// * Quick sort is currently disable! in pick_sort()
			for (int a = 0; a < 8; a++)
			{
				copyArray(arrA, arrB, size[j]);
				runSort(arrB, size[j], index++);
			}
			file << "-------------------" << endl;
		}
		cout << endl;
	}
}