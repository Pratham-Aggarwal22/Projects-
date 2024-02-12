#include <iostream>
#include <ctime>
#include "sorts.h"
#include "generate.h"
using namespace std;

// Function to perform Radix Sort on an array of integers
// Parameters:
//   A: The array to be sorted
//   n: The size of the array 
void RadixSort(int A[], int n) {
	int digit = 0; // Variable to store the number of digits in the maximum element
	int* C = new int[10]; // Auxiliary array for counting occurrences of digits
	int* B = new int[n]; // Output array to store sorted elements

	// Find the maximum element in the array
	int max = A[0];
	for (int i = 1; i < n; i++) {
		if (A[i] > max) {
			max = A[i];
		}
	}

	// Find the number of digits in the maximum element
	while (max > 0) {
		digit++;
		max = max / 10;
	}

	// Radix sorting process
	for (int j = 1; j <= int(pow(10, digit - 1)); j = j * 10) {
		// Reset all elements in the auxiliary array to 0
		for (int i = 0; i < 10; i++) {
			C[i] = 0;
		}

		// Count the occurrences of each digit in the array
		for (int i = 0; i < n; i++) {
			C[(A[i] / j) % 10] = C[(A[i] / j) % 10] + 1;
		}

		// Cumulatively add values in the auxiliary array
		for (int i = 1; i <= 9; i++) {
			C[i] = C[i] + C[i - 1];
		}

		// Rearrange elements in the output array based on digit occurrences
		for (int i = n - 1; i >= 0; i--) {
			B[C[(A[i] / j) % 10] - 1] = A[i];
			C[(A[i] / j) % 10] = C[(A[i] / j) % 10] - 1;
		}

		// Copy the sorted output array back to the original array A
		for (int i = 0; i < n; i++) {
			A[i] = B[i];
		}
	}

	return;
}

// Function to test the RadixSort algorithm with different input scenarios and measure execution times
// Parameters:
//   arr_size: The size of the arrays to be generated and sorted
void RadixSortTest(int arr_size) {
	// Data Generation
	int* highDigit_arr = new int[arr_size];
	int* random_arr = new int[arr_size];
	int* lowRange_arr = new int[arr_size];

	highDigitGen(highDigit_arr, arr_size); // Generate an array with high digits
	randomGen(random_arr, arr_size); // Generate a randomly ordered array
	lowRangeGen(lowRange_arr, arr_size); // Generate an array with low range values

	// Timer
	clock_t time_taken;

	// Worst Case
	time_taken = clock();
	RadixSort(highDigit_arr, arr_size); // Perform RadixSort on an array with high digits
	time_taken = clock() - time_taken;
	cout << "Worst Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	// Average Case
	time_taken = clock();
	RadixSort(random_arr, arr_size); // Perform RadixSort on a randomly ordered array
	time_taken = clock() - time_taken;
	cout << "Average Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	// Best Case
	time_taken = clock();
	RadixSort(lowRange_arr, arr_size); // Perform RadixSort on an array with low range values
	time_taken = clock() - time_taken;
	cout << "Best Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;
}