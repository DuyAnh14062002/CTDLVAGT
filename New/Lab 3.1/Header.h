#pragma once
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
// GenerateData.cpp
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

// SortingAlgorithm.cpp
void selectionSort(int* arr, int n);
void heapRebuild(int index, int* arr, int n);
void heapConstruct(int* arr, int n);
void heapSort(int* arr, int n);
void merge(int a[], int left, int mid, int right);
void mergeSort(int a[], int left, int right);
void insertionSort(int a[], int n);
void bubbleSort(int arr[], int n);
int partition(int a[], int first, int last);
void quickSort(int a[], int first, int last);
void radixSort(int a[], int n);
void shakerSort(int a[], int n);

// CountFunction.cpp
void selection_sort_count(int* arr, int n, long long int& count_cmp);
void heap_rebuild_count(int index, int* arr, int n, long long int& count_cmp);
void heap_construct_count(int* arr, int n, long long int& count_cmp);
void heap_sort_count(int* arr, int n, long long int& count_cmp);
void bubble_sort_count(int arr[], int n, long long int& count_cmp);
void insertion_sort_count(int a[], int n, long long int& count_cmp);
void radix_sort_count(int a[], int n, long long int& count_cmp);
void shaker_sort_count(int a[], int n, long long int& count_cmp);
void merge_count(int a[], int left, int mid, int right, long long int& count_cmp);
void merge_sort_count(int a[], int left, int right, long long int& count_cmp);
int partition_count(int a[], int first, int last, long long int& count_cmp);
void quick_sort_count(int a[], int first, int last, long long int& count_cmp);

// Source.cpp
void pick_sort_count(int* arr, int size, long long int& count_cmp, int index);
void pickSort(int* arr, int size, int index);
void copyArray(int* arrA, int*& arrB, int size);
void run_Selection(int* arr, int size);
void run_Heap(int* arr, int size);
void run_BubbleSort(int* arr, int size);
void experiments();
void swap1(int& a, int& b);