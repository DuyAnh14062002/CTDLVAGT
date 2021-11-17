#include <iostream>
using namespace std;

#define MAX 5

void printArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

void radixSort(int* a, int n)
{
	int b[MAX], m = a[0], exp = 1;

	for (int i = 0; i < n; i++)// Tim so lon nhat
	{
		if (a[i] > m)
			m = a[i];
	}
	while (m / exp > 0)// 25 5 9 10 6
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
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int j = Right; j > Left; j--)
		{
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
				k = j;
			}
		}
		Left = k;
	}
}
int main()
{
	int arr[MAX] = { 25, 5, 9, 10, 6 };
	int n=sizeof(arr)/sizeof(arr[0]);

	cout << endl << "Before sort : ";
	printArray(arr, n);

	//radixSort(arr, n);
	shakerSort(arr, n);
	cout << endl << "After sort : ";
	printArray(arr, n);

	return 0;
}