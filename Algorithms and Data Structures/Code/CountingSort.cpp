#include <iostream>
#include <ctime>
#include "sorts.h"
#include "generate.h"
using namespace std;

// Function to perform Counting Sort on an array of integers
// Parameters:
//   A: The array to be sorted
//   n: The size of the array
void CountingSort(int A[], int n) {
	// Find the maximum element in the array
	int max = A[0];
	for (int i = 1; i < n; i++) {
		if (A[i] > max) {
			max = A[i];
		}
	}

	int* C = new int[max + 1]; // Auxiliary array for counting occurrences of elements
	int* B = new int[n]; // Output array to store sorted elements

	// Reset all elements in the auxiliary array to 0
	for (int i = 0; i < max + 1; i++) {
		C[i] = 0;
	}

	// Count the occurrences of each element in the array
	for (int i = 0; i < n; i++) {
		C[A[i]] = C[A[i]] + 1;
	}

	// Cumulatively add values in the auxiliary array
	for (int i = 1; i < max + 1; i++) {
		C[i] = C[i] + C[i - 1];
	}

	// Rearrange elements in the output array based on element occurrences
	for (int i = n - 1; i >= 0; i--) {
		B[C[A[i]] - 1] = A[i];
		C[A[i]] = C[A[i]] - 1;
	}

	/*
	// Copy B to A. Since C++ does not allow arrays to be returned from functions,
	// this is one of the simpler ways to return the sorted array
	for (int i = 0; i < n; i++) {
		A[i] = B[i];
	}*/

	return;
}

// Function to test the CountingSort algorithm with different input scenarios and measure execution times
// Parameters:
//   arr_size: The size of the arrays to be generated and sorted
void CountingSortTest(int arr_size) {
	// Data Generation
	int* highRange_arr = new int[arr_size];
	int* random_arr = new int[arr_size];
	int* lowRange_arr = new int[arr_size];

	highRangeGen(highRange_arr, arr_size); // Generate an array with high range values
	randomGen(random_arr, arr_size); // Generate a randomly ordered array
	lowRangeGen(lowRange_arr, arr_size); // Generate an array with low range values

	// Timer
	clock_t time_taken;

	// Worst Case
	time_taken = clock();
	CountingSort(highRange_arr, arr_size); // Perform CountingSort on an array with high range values
	time_taken = clock() - time_taken;
	cout << "Worst Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	// Average Case
	time_taken = clock();
	CountingSort(random_arr, arr_size); // Perform CountingSort on a randomly ordered array
	time_taken = clock() - time_taken;
	cout << "Average Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	// Best Case
	time_taken = clock();
	CountingSort(lowRange_arr, arr_size); // Perform CountingSort on an array with low range values
	time_taken = clock() - time_taken;
	cout << "Best Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	return;
}