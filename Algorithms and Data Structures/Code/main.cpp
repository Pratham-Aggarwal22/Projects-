#include <iostream>
#include <ctime>
#include "sorts.h" // contains the sorting algorithms
#include "generate.h" // contains the generation for data sets
using namespace std;

int main()
{
    // Prompt the user to enter the input size
    cout << "Enter an input size (must be positive): " << endl << endl;
    int arr_size;
    cin >> arr_size;

    int repeat = 1;

    // Repeat until the user chooses to terminate the program
    while (repeat == 1) {
        // Prompt the user to select a sorting algorithm
        cout << "Select a sorting algorithm: " << endl << endl;

        // Display the available sorting algorithms
        cout << "1: Insertion Sort" << endl;
        cout << "2: Selection Sort" << endl;
        cout << "3: Bubble Sort" << endl;
        cout << "4: Merge Sort" << endl;
        cout << "5: Quick Sort" << endl;
        cout << "6: Heap Sort" << endl;
        cout << "7: Counting Sort" << endl;
        cout << "8: Radix Sort" << endl;
        cout << "9: TERMINATE PROGRAM" << endl;

        int input;
        cin >> input;

        // Check if the user wants to terminate the program
        if (input == 9) {
            break;
        }

        // Perform the sorting algorithm based on user input
        switch (input) {
        case 1:
            InsertionSortTest(arr_size);
            break;
        case 2:
            SelectionSortTest(arr_size);
            break;
        case 3:
            BubbleSortTest(arr_size);
            break;
        case 4:
            MergeSortTest(arr_size);
            break;
            // NOTE: If the array size is too big, Stack Overflow Error will occur for worst case
        case 5:
            QuickSortTest(arr_size);
            break;
        case 6:
            HeapSortTest(arr_size);
            break;
            // NOTE: If the array size is too big, Stack Overflow Error will occur for worst case
        case 7:
            CountingSortTest(arr_size);
            break;
        case 8:
            RadixSortTest(arr_size);
        }
    }

    return 0;
}