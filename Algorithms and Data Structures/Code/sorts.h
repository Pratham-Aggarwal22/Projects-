#pragma once

void InsertionSort(int arr[], int n); // Sorts an array using the insertion sort algorithm.
void InsertionSortTest(int arr_size);

void SelectionSort(int arr[], int n); // Sorts an array using the selection sort algorithm.
void SelectionSortTest(int arr_size);

void BubbleSort(int arr[], int n); // Sorts an array using the bubble sort algorithm.
void BubbleSortTest(int arr_size);

void Merge(int arr[], int left, int middle, int right); // Helper Function for merge sort, used to merge two sorted subarrays into a single array.
void MergeSort(int arr[], int left, int right); // Sorts an array using the merge sort algorithm.
void MergeSortTest(int arr_size);

int Partition(int arr[], int low, int high, int sel); // Helper Function for quick sort, used to partition an array into two parts based on the pivot (sel).
void QuickSort(int arr[], int p, int r, int sel); // Sorts an array using the quick sort algorithm with a selected pivot (sel).
void QuickSortTest(int arr_size);

class Heap
{
public:
	int* heap_arr;
	int heap_size;
	int max_size = 1000000;
	Heap(int arr[], int arr_size);

	void insert_value_maxHeap(int val); //Adds value at the end of array and calls max_heapify
	void max_heapify(int i, int n); //Maintains the max heap property
	void HeapSort(); //Prints the array in ascending order
	void buildMaxHeap(); //Heapifies entire list
};
void HeapSortTest(int arr_size);

void CountingSort(int A[], int n); // Sorts an array using the counting sort algorithm.
void CountingSortTest(int arr_size);

void RadixSort(int A[], int n); // Sorts an array using the radix sort algorithm.
void RadixSortTest(int arr_size);