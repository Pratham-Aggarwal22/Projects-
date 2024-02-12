#include <iostream>
#include <ctime>
#include "sorts.h"
#include "generate.h"
using namespace std;

// Function to merge two subarrays into a sorted array
// Parameters:
//   arr: The array to be sorted
//   left: Index of the leftmost element of the subarray
//   middle: Index of the middle element of the subarray
//   right: Index of the rightmost element of the subarray
void Merge(int arr[], int left, int middle, int right) {
	int mergedIndex = left;
	int* leftArr = new int[middle - left + 1];
	int* rightArr = new int[right - middle];

	// Copy elements to leftArr = A[left..middle]
	for (int i = 0; i < middle - left + 1; ++i) {
		leftArr[i] = arr[left + i];
	}

	// Copy elements to rightArr = A[middle+1..right]
	for (int i = 0; i < right - middle; ++i) {
		rightArr[i] = arr[middle + 1 + i];
	}

	int leftIndex = 0;
	int rightIndex = 0;

	// Merge the two subarrays into a sorted array
	while (leftIndex < (middle - left + 1) && rightIndex < (right - middle)) {
		// Copy the smaller element into A[mergedIndex]
		if (leftArr[leftIndex] < rightArr[rightIndex]) {
			arr[mergedIndex] = leftArr[leftIndex];
			leftIndex++;
		}
		else {
			arr[mergedIndex] = rightArr[rightIndex];
			rightIndex++;
		}
		mergedIndex++;
	}

	// Copy the remaining elements of the non-empty arrays to the merged array
	while (leftIndex < middle - left + 1) {
		arr[mergedIndex] = leftArr[leftIndex];
		mergedIndex++;
		leftIndex++;
	}

	// Copy the remaining elements of the non-empty arrays to the merged array
	while (leftIndex < right - middle) {
		arr[mergedIndex] = rightArr[leftIndex];
		mergedIndex++;
		rightIndex++;
	}

	// Memory Cleanup
	delete[] leftArr;
	delete[] rightArr;
	return;
}

// Function to perform Merge Sort on an array of integers
// Parameters:
//   arr: The array to be sorted
//   left: Index of the leftmost element of the array
//   right: Index of the rightmost element of the array
void MergeSort(int arr[], int left, int right) {
	int middle;

	if (left < right) {
		middle = (left + right) / 2;

		// Array is divided into two halves
		MergeSort(arr, left, middle);
		MergeSort(arr, middle + 1, right);

		// The two halves are merged into a sorted array
		Merge(arr, left, middle, right);
	}
	return;
}

// Function to test the MergeSort algorithm with different input scenarios and measure execution times
// Parameters:
//   arr_size: The size of the arrays to be generated and sorted
void MergeSortTest(int arr_size) {
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
	MergeSort(unsorted_arr, 0, arr_size - 1);
	time_taken = clock() - time_taken;
	cout << "Worst Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	// Average Case
	time_taken = clock();
	MergeSort(halfSorted_arr, 0, arr_size - 1);
	time_taken = clock() - time_taken;
	cout << "Average Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	// Best Case
	time_taken = clock();
	MergeSort(sorted_arr, 0, arr_size - 1);
	time_taken = clock() - time_taken;
	cout << "Best Case Execution Time: " << ((float)time_taken) / CLOCKS_PER_SEC << " seconds" << endl << endl;

	return;
}