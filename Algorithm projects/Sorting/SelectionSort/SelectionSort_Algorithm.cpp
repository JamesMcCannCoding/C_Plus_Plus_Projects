#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;

const int ARRAY_SIZE = 15;

// Function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to perform selection sort
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;                 // This min_index variable is the smallest value in the un-sorted portion of the array.
        for (int j = i + 1; j < size; j++) // j = i + 1 Checks the rest of the elements in the un-sorted portion of the array.
        {
            if (arr[j] < arr[min_index]) // If this loop finds an element that is less than the element stored in min_index, it will update min_index and set it to the index of that element.
            {
                min_index = j;
            }
        }
        if (min_index != i) // Checks if min_index is valid and needs to swap.
        {
            swap(arr[i], arr[min_index]);
        }

        // Print the array after each iteration
        cout << "After iteration " << (i + 1) << ": ";
        printArray(arr, size);
    }
}

int main()
{
    int arr[ARRAY_SIZE];

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate random numbers and fill the array
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = 1 + rand() % 100; // Generates a number between 1 and 100
    }

    cout << "Original array: ";
    printArray(arr, ARRAY_SIZE);

    // Record the start time
    auto start = chrono::high_resolution_clock::now();

    // Sort the array
    selectionSort(arr, ARRAY_SIZE);

    // Record the end time
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsed = end - start;
    int elapsedMillis = static_cast<int>(elapsed.count() * 1000);

    cout << "Sorted array: ";
    printArray(arr, ARRAY_SIZE);

    cout << "Time taken to sort: " << elapsed.count() << " seconds (" << elapsedMillis << " milliseconds)." << endl;

    return 0;
}
