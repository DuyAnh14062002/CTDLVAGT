#pragma once
#include "GenerateData.h"
#include "RunTime.h"
void selection_sort(int* arr, int n);
void insertionSort_Com(int a[], int n, int& count_ass, int& count_com);
void merge_com(int a[], int left, int mid, int right, int& count_ass, int& count_com);
void mergeSort_com(int a[], int left, int right, int& count_ass, int& count_com);
void heapRebuild(int index, int* arr, int n);
void heapConstruct(int* arr, int n);
void heap_sort(int* arr, int n);
void MenuRunTime(int a[], int n, int sort, int& count_ass, int& count_com);
void bubbleSort(int arr[], int n);
int partition(int arr[], int low, int high);
int Comparions();