#include <iostream>
#include <ctime>
#include "sorts.h"
#include "generate.h"
using namespace std;

// Function to perform Bubble Sort on an array of integers
// Parameters:
//   arr: The array to be sorted
//   n: The size of the array
void BubbleSort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]); // Swap elements if they are in the wrong order
			}
		}
	}
	return;
}

// Function to test the BubbleSort algorithm with different input scenarios and measure execution times
// Parameters:
//   arr_size: The size of the arrays to be generated and sorted
void BubbleSortTest(int arr_size) {
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
	BubbleSort(unsorted_arr, arr_size); // Perform BubbleSort on an unsorted array
	time_taken = clock() - time_taken;
	cout << "Worst Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	// Average Case
	time_taken = clock();
	BubbleSort(halfSorted_arr, arr_size); // Perform BubbleSort on a partially sorted array
	time_taken = clock() - time_taken;
	cout << "Average Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	// Best Case
	time_taken = clock();
	BubbleSort(sorted_arr, arr_size); // Perform BubbleSort on a fully sorted array
	time_taken = clock() - time_taken;
	cout << "Best Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	return;
}