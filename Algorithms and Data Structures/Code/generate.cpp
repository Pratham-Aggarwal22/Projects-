#include <iostream>
#include <math.h>
#include "generate.h"
using namespace std;


// This function generates a random array
void randomGen(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % n; // fills array with random numbers
	}
	return;
}

// This function generates a fully unsorted array
void unsortedGen(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = n-1-i; // fills array with descending values
	}
	return;
}

// This function generates fully sorted array
void sortedGen(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = i; // fills array with ascending values
	}
	return;
}

// This function generates a half sorted array
void halfSortedGen(int arr[], int n) {
	for (int i = 0; i < n/2; i++) {
		arr[i] = n-1-i; // fills array with descending values
	}
	for (int i = n/2; i < n; i++) {
		arr[i] = i; // fills array with ascending values
	}
	return;
}

// This function generates an array with a high range 
void highRangeGen(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = pow(n, 3.0/2); // fills array with n^(3/2)
	}
	return;
}

// This function generates an array with only elements of value 0
void lowRangeGen(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = 0; // fills array with 0s
	}
	return;
}

// This function generates an array with a high number of digits
void highDigitGen(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = i * 1000; // fills array with numbers with many digits
	}
	return;
}