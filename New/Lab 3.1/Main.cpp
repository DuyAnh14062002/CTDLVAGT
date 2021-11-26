#include "Header.h"


int main()
{
	//fstream file;
	//file.open("chart.txt", ios::out);

	//auto start = high_resolution_clock::now();
	//experiments(); // thay doi i, j va dieu kien trong ham experiments de chon data type va data size
	//auto stop = high_resolution_clock::now();
	//auto duration = duration_cast<seconds>(stop - start);

	//cout << "total time taken: " << duration.count() << " seconds" << endl;

	//file.close();
	//// ghi tong thoi gian vao cuoi file
	//file.open("chart.txt", ios::app);
	//file.seekp(file.eof());
	//file << "total time taken: " << duration.count() << " seconds" << endl;
	//file.close();


	// test ham sorting nhanh
	//int arr[10] = { 4,8,5,0,2,7,11,9,3,10 };
	//int n = 10, count_cmp = 0;
	//// *insert sorting algorithm here to test* 
	//quickSort(arr, 0, 9);
	//for (int i = 0; i < n; i++)
	//{
	//	cout << arr[i] << " ";
	//}

	//int n = 100;
	//int* arr = new int[n];
	int n;
	readSize(n);
	int* arr = new int[n];
	GenerateData(arr, n,2);
	//readFileArray(arr,n);
	mergeSort(arr, 0, n-1);
	//writeFileArray(arr, n, 0);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}