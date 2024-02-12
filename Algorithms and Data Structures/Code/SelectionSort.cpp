#include <iostream>
#include <ctime>
#include "sorts.h"
#include "generate.h"
using namespace std;

// Function to perform Selection Sort on an array of integers
// Parameters:
//   arr: The array to be sorted
//   n: The size of the array 
void SelectionSort(int arr[], int n) {
	int temp;
	int minIndex; // Index of the minimum element

	for (int i = 0; i < n - 1; i++) {
		minIndex = i;

		// Find the minimum element from A[i+1] to A[n-1]
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}

		// Swap the minimum element with arr[i]
		temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}

	return;
}

// Function to test the SelectionSort algorithm with different input scenarios and measure execution times
// Parameters:
//   arr_size: The size of the arrays to be generated and sorted
void SelectionSortTest(int arr_size) {
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
	SelectionSort(unsorted_arr, arr_size); // Perform SelectionSort on an unsorted array
	time_taken = clock() - time_taken;
	cout << "Worst Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	// Average Case
	time_taken = clock();
	SelectionSort(halfSorted_arr, arr_size); // Perform SelectionSort on a partially sorted array
	time_taken = clock() - time_taken;
	cout << "Average Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	// Best Case
	time_taken = clock();
	SelectionSort(sorted_arr, arr_size); // Perform SelectionSort on a fully sorted array
	time_taken = clock() - time_taken;
	cout << "Best Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	return;
}