#include <iostream>
#include <ctime>
#include "sorts.h"
#include "generate.h"
using namespace std;

// Function to perform Insertion Sort on an array of integers
// Parameters:
//   arr: The array to be sorted
//   n: The size of the array
void InsertionSort(int arr[], int n) {
	for (int j = 1; j < n; j++) {
		int key = arr[j]; // Current element to be inserted at the correct position
		int i = j - 1;

		// Move elements greater than key to one position ahead of their current position
		while (i >= 0 && arr[i] > key) {
			arr[i + 1] = arr[i];
			i = i - 1;
		}

		arr[i + 1] = key; // Place the key at its correct position in the sorted part of the array
	}

	return;
}

// Function to test the InsertionSort algorithm with different input scenarios and measure execution times
// Parameters:
//   arr_size: The size of the arrays to be generated and sorted
void InsertionSortTest(int arr_size) {
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
	time_taken = clock();
	InsertionSort(unsorted_arr, arr_size); // Perform InsertionSort on an unsorted array
	time_taken = clock() - time_taken;
	cout << "Worst Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	// Average Case
	time_taken = clock();
	InsertionSort(halfSorted_arr, arr_size); // Perform InsertionSort on a partially sorted array
	time_taken = clock() - time_taken;
	cout << "Average Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	// Best Case
	time_taken = clock();
	InsertionSort(sorted_arr, arr_size); // Perform InsertionSort on a fully sorted array
	time_taken = clock() - time_taken;
	cout << "Best Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	return;
}