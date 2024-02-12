#include <iostream>
#include <ctime>
#include "sorts.h"
#include "generate.h"
using namespace std;

// Constructor for the Heap class
// Parameters:
//   arr: The input array to initialize the heap
//   arr_size: The size of the input array
Heap::Heap(int arr[], int arr_size) {
	this->heap_arr = new int[this->max_size];
	this->heap_size = arr_size; // Heap array size set to input array size

	// Input array is copied into the heap array
	for (int i = 0; i < arr_size; i++) {
		this->heap_arr[i] = arr[i];
	}
	buildMaxHeap(); // Build a max heap from the input array

	return;
}

// Function to perform Heap Sort on the heap
void Heap::HeapSort() {
	buildMaxHeap(); // Ensure that the heap is in max heap order
	Heap temp_heap(this->heap_arr, this->heap_size); // Create a temporary heap
	for (int i = this->heap_size - 1; i > 0; i--) {
		swap(temp_heap.heap_arr[i], temp_heap.heap_arr[0]); // Swap the root with the last element
		temp_heap.max_heapify(0, i - 1); // Restore max heap property
	}

	return;
}

// Function to maintain the max heap property
// Parameters:
//   i: Index of the element to be heapified
//   n: Size of the heap
void Heap::max_heapify(int i, int n) {
	int largest = i;
	int l_child = 2 * i + 1;
	int r_child = 2 * i + 2;
	if (l_child <= n && this->heap_arr[l_child] > this->heap_arr[i]) {
		largest = l_child;
	}
	if (r_child <= n && this->heap_arr[r_child] > this->heap_arr[largest]) {
		largest = r_child;
	}
	if (largest != i) {
		swap(this->heap_arr[i], this->heap_arr[largest]);
		max_heapify(largest, n);
	}
}

// Function to insert a value into the max heap
// Parameters:
//   val: The value to be inserted
void Heap::insert_value_maxHeap(int val) {
	if (this->heap_size < this->max_size) {
		this->heap_size += 1;
		this->heap_arr[this->heap_size - 1] = val;
		int i = this->heap_size - 1;
		while (i > 0 && this->heap_arr[i] > this->heap_arr[(i - 1) / 2]) {
			swap(this->heap_arr[(i - 1) / 2], this->heap_arr[i]);
			i = (i - 1) / 2;
		}
	}
	else {
		cout << "Error: max heap size reached" << endl;
	}

	return;
}

// Function to build a max heap from the heap array
void Heap::buildMaxHeap() {
	for (int i = (this->heap_size - 1) / 2; i >= 0; i--) {
		max_heapify(i, this->heap_size - 1);
	}

	return;
}

// Function to test the HeapSort algorithm with different input scenarios and measure execution times
// Parameters:
//   arr_size: The size of the arrays to be generated and sorted
void HeapSortTest(int arr_size) {
	// Data Generation
	int* unsorted_arr = new int[arr_size];
	int* sorted_arr = new int[arr_size];
	int* halfSorted_arr = new int[arr_size];

	unsortedGen(unsorted_arr, arr_size); // Generate an unsorted array
	sortedGen(sorted_arr, arr_size); // Generate a sorted array
	halfSortedGen(halfSorted_arr, arr_size); // Generate an array that is half sorted

	// Timer
	clock_t time_taken;

	// Worst Case
	Heap* unsorted = new Heap(unsorted_arr, arr_size);
	time_taken = clock();
	unsorted->HeapSort();
	time_taken = clock() - time_taken;
	cout << "Worst Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	// Average Case
	Heap* halfsorted = new Heap(halfSorted_arr, arr_size);
	time_taken = clock();
	halfsorted->HeapSort();
	time_taken = clock() - time_taken;
	cout << "Average Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	// Best Case
	Heap* sorted = new Heap(sorted_arr, arr_size);
	time_taken = clock();
	sorted->HeapSort();
	time_taken = clock() - time_taken;
	cout << "Best Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	return;
}