#include <iostream>
#include <ctime>
#include "sorts.h"
#include "generate.h"
using namespace std;

// Function to partition the array for QuickSort
// Parameters:
//   arr: The array to be partitioned
//   low: The lower index of the array or subarray
//   high: The higher index of the array or subarray
//   sel: The selection strategy for choosing the pivot (1 = 1st element, 2 = random element, else = median of three elements)
// Returns:
//   The index of the pivot after partitioning
int Partition(int arr[], int low, int high, int sel) {
	int x; // Pivot element

	// Choose pivot based on the selection strategy
	if (sel == 1) {
		x = arr[low]; // Select the first element as pivot
	}
	else if (sel == 2) {
		x = arr[rand() % (high - low + 1) + low]; // Randomly select a pivot
	}
	else {
		int mid = low + (high - low) / 2; // Calculate the middle index

		// Compute the median of the three elements as pivot
		x = arr[mid];
		if ((arr[low] <= arr[mid] && arr[mid] <= arr[high]) || (arr[high] <= arr[mid] && arr[mid] <= arr[low])) {
			x = arr[mid];
		}
		else if ((arr[mid] <= arr[low] && arr[low] <= arr[high]) || (arr[high] <= arr[low] && arr[low] <= arr[mid])) {
			x = arr[low];
		}
		else {
			x = arr[high];
		}
	}

	int i = low - 1; // Index of smaller element
	int j = high + 1; // Index of larger element

	// Partition the array
	while (true) {
		do {
			j--;
		} while (arr[j] > x);
		do {
			i++;
		} while (arr[i] < x);
		if (i < j) {
			swap(arr[i], arr[j]); // Swap elements if out of order
		}
		else {
			return j; // Return the index of the pivot
		}
	}
}

// Function to perform QuickSort on the array
// Parameters:
//   arr: The array to be sorted
//   p: The starting index of the array or subarray
//   r: The ending index of the array or subarray
//   sel: The selection strategy for choosing the pivot (1 = 1st element, 2 = random element, else = median of three elements)
void QuickSort(int arr[], int p, int r, int sel) {
	if (p < r) {
		int q = Partition(arr, p, r, sel); // Partition the array and get the pivot index
		QuickSort(arr, p, q, sel); // Recursively sort the elements before the pivot
		QuickSort(arr, q + 1, r, sel); // Recursively sort the elements after the pivot
	}
	return;
}

// Function to test the QuickSort algorithm with different pivot selection strategies and measure execution times
// Parameters:
//   arr_size: The size of the arrays to be generated and sorted
void QuickSortTest(int arr_size) {
	// Data Generation
	int* unsorted_arr = new int[arr_size];
	int* random_arr = new int[arr_size];
	int* sorted_arr = new int[arr_size];

	unsortedGen(unsorted_arr, arr_size); // Generate an unsorted array
	randomGen(random_arr, arr_size); // Generate a randomly ordered array
	sortedGen(sorted_arr, arr_size); // Generate a sorted array

	// Timer
	clock_t time_taken;
	// Worst Case
	time_taken = clock();
	QuickSort(unsorted_arr, 0, arr_size - 1, 1); // First element as pivot
	time_taken = clock() - time_taken;
	cout << "Worst Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	// Average Case
	time_taken = clock();
	QuickSort(random_arr, 0, arr_size - 1, 2); // Random element as pivot
	time_taken = clock() - time_taken;
	cout << "Average Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	// Best Case
	time_taken = clock();
	QuickSort(sorted_arr, 0, arr_size - 1, 3); // Middle element as pivot
	time_taken = clock() - time_taken;
	cout << "Best Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;
}