#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

// Sorting function 1: Bubble Sort 
// Sorting the elements using Bubble sorting, it takes vector of integers 'arr' as input  
void bubbleSort(vector<int>& arr)
{
    int s = arr.size();  // initializing variable 's' with the size of the vector
    for (int i = 0; i < s - 1; i++) // outer loop: iterating from the first element of the vector until the second-last element
    {
        for (int j = i + 1; j < s; j++) // Inner loop: For the unsorted portion of the vector, starting from the  element following the current element of the outer loop
        {
            if (arr[i] > arr[j]) // checks if the current element is greater than the next element
            {
                swap(arr[i], arr[j]); // It swaps the position of those elements if the condition is true
            }
        }
    }
}


// Sorting function 2: Selection Sort
// Sorting the elements using selection sort, it takes vector of integers 'arr' as input  
void selectionSort(vector<int>& arr)
{
    int s = arr.size(); // initializing variable 's' with the size of the vector
    for (int i = 0; i < s - 1; i++) // outer loop: iterating from the first element of the vector until the second-last element
    {
        int curr_min = i;  // Initializing a variable 'curr_min' with the index of the current element, basically considering it as the current minimum element
        for (int j = i + 1; j < s; j++)  // Inner loop: For the unsorted portion of the vector, starting from the  element following the current element of the outer loop
        {
            if (arr[j] < arr[curr_min]) // checks whether the element at index 'j' is smaller than the current minimum element 
            {
                curr_min = j; // If the condition is true, the value of 'curr_min' is changed to the value at index 'j'
            }
        }
        swap(arr[i], arr[curr_min]); // swaps the current element at index 'i' with the minimum element at index 'curr_min'
    }
}

// Sorting function 3: Insertion Sort
// Sorting the elements using insertion sort, it takes vector of integers 'arr' as input  
void insertionSort(vector<int>& arr)
{
    int s = arr.size(); // initializing variable 's' with the size of the vector
    for (int i = 1; i < s; i++) // Iterating through the loop starting from the second element to the last one
    {
        int key = arr[i]; // Initializing a variable 'key' with the current element
        int j = i - 1; // Initializing a variable 'j' to the previous element of the current element
        while (j >= 0 && arr[j] > key) // checks if the index 'j' is greater than equal to 0 and the element at 'j' is greater than the 'key' element
        {
            arr[j + 1] = arr[j]; // shifting the element at 'j' one index forward 
            j--; // setting the index value of 'j' to the previous index 
        }
        arr[j + 1] = key; //  Inserting the 'key' element into the sorted portion of the vector at index 'j+1'
    }
}

// Sorting function 4: Merge Sort
// Sorting the elements using merge sort, first we call the define the merge function, it takes vector of integers 'arr' and three integers l, m and r as input; l - left subarray, r- right subarray
void merge(vector<int>& arr, int l, int m, int r)
{
    int s1 = m - l + 1; // initializing a variable s1 to the size of the left subarray
    int s2 = r - m; // initializing a variable s2 to the size of the right subarray
    vector<int> lArr(s1), rArr(s2); // lArr and rArr are the two arrays that store left and right subarrays 

    for (int i = 0; i < s1; i++) // loop to add the left elements of the original array to the 'lArr'
    {
        lArr[i] = arr[l + i]; // adding the elements at each index
    }
    for (int j = 0; j < s2; j++)  // loop to add the right elements of the original array to the 'rArr'
    {
        rArr[j] = arr[m + 1 + j]; // adding the elements at each index
    }

    int i = 0, j = 0, k = l; // initializing three variables to traverse through the original and sub-array
    while (i < s1 && j < s2)  // loop is executed till the indexes of both the subarray becomes greater than their size
    {
        // checks which value of is greater on the same index of both the subarrays
        if (lArr[i] <= rArr[j]) // if the value at right subarray is greater
        {
            arr[k] = lArr[i]; // then it adds the value of the left subarray to the original array
            // incrementing both i and k
            k++;
            i++;
        }
        else
        {
            arr[k] = rArr[j]; // otherwise it add the value of right subarray to the original array 
            //incrementing both j and k
            k++;
            j++;
        }
    }
    // remaining elements of the left subarray are appended to the original array
    while (i < s1)
    {
        arr[k++] = lArr[i++];
    }
    // remaining elements of the right subarray are appended to the original array
    while (j < s2) {
        arr[k++] = rArr[j++];
    }
}
// This function implements the merge sort algorithm 
void mergeSort(vector<int>& arr, int l, int r)
{
    if (l < r) // checks if there is only one element
    {
        // if left subarray index is less than right subarray index
        int m = l + (r - l) / 2; // Initializing a variable 'm' and computing the mid-point of the array
        mergeSort(arr, l, m); // Recursive calling of the function to sort the left subarray
        mergeSort(arr, m + 1, r); // Recursive calling of the function to sort the right subarray
        merge(arr, l, m, r); // merging the two sorted arrays
    }
}

// Sorting function 5: Quick Sort
// Sorting the elements using quick sort, first we call the define the partition function, it takes vector of integers 'arr' and two integers low and high. This function divides the list in such a way that all the elements smaller than pivot element are on the left side and all the greater ones are on the right side
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high]; // Initialising a pivot element and set it to the last element
    int i = low - 1; // Initialising a variable i to a index one smaller than the lower index
    for (int j = low; j <= high - 1; j++) // iterating through the loop from lower index to one less than the higher index
    {
        if (arr[j] < pivot) // checks if current elements is smaller than the pivot element
        {
            i++; // increments the index with one
            swap(arr[i], arr[j]); // swaps the current element with the element at the index of the smaller element 
        }
    }
    swap(arr[i + 1], arr[high]); // swaps the pivot element with the element at the index next to the smaller element
    return i + 1; // returning the index of pivot element
}
// This function implements the quick sort algorithm
void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high) // Checks if the vector has more than one element
    {
        int pivot = partition(arr, low, high); // Initialising the pivot element, basically finiding the index of pivot element
        quickSort(arr, low, pivot - 1); // sorting the elements left to the pivot element
        quickSort(arr, pivot + 1, high); // sorting the elements right to the pivot element
    }
}

int main() {


    // Initialize random number generator
    srand(time(NULL));


    const int N = 10000000;
    vector<int> InitV(N);
    // Fill InitV with random integers
    for (int i = 0; i < N; i++)
    {
        InitV[i] = (rand() % 100000) + 1; // we are using 1000000 to get different numbers after sorting
    }

    // Loop for different sizes of M
    for (int M = 200000; M <= N; M += 200000) {
        // Create a copy of the first M elements of InitV
        vector<int> V(M);
        for (int i = 0; i < M; i++) {
            V[i] = InitV[i];
        }

        // Print the first 100 elements before sorting
        cout << "\n\nBefore sorting: ";
        for (int i = 0; i < min(100, M); i++)
        {
            cout << V[i] << " ";
        }
        cout << endl;

        // Record start time
        auto start = chrono::high_resolution_clock::now();

        // Call each sorting algorithm and record time taken
        bubbleSort(V);
        //selectionSort(V);
        //insertionSort(V);
        //mergeSort(V, 0, M-1);
        //quickSort(V, 0, M-1);

        // Record end time
        auto end = chrono::high_resolution_clock::now();

        // Print the first 100 elements after sorting
        cout << "After sorting: ";
        for (int i = 0; i < min(100, M); i++) {
            cout << V[i] << " ";
        }
        cout << endl;

        // Compute time taken
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << "\nTime taken for M = " << M << " is " << duration << " milliseconds." << endl;

    }

    return 0;
}
