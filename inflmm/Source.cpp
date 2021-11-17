#include <iostream>

using namespace std;

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

int main()
{
	int arr[10] = { 4,8,5,0,2,7,11,9,3,10 };
	int n = 10;
	//selection_sort(arr, n);
	heapConstruct(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	heap_sort(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}