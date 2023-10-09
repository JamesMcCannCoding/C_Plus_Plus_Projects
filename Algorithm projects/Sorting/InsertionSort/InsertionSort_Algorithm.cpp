#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

// Function to perform insertion sort on the given array
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // Print the array after this iteration
        cout << "After iteration " << i << ": ";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    const int SIZE = 20;
    int arr[SIZE];

    // Seed the random number generator with the current time
    srand(time(nullptr));

    // Generate and print the unsorted array
    cout << "Unsorted array: ";
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = 1 + rand() % 100; // random numbers between 1 and 100
        cout << arr[i] << " ";
    }
    cout << endl;

    // Get the starting time
    auto start = chrono::high_resolution_clock::now();

    // Perform insertion sort on the array
    insertionSort(arr, SIZE);

    // Get the ending time
    auto stop = chrono::high_resolution_clock::now();
    auto durationSeconds = chrono::duration_cast<chrono::seconds>(stop - start);
    auto durationMilliseconds = chrono::duration_cast<chrono::milliseconds>(stop - start);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print the time taken to sort the array
    cout << "Time taken to sort: " << durationSeconds.count() << " seconds (or " << durationMilliseconds.count() << " milliseconds)" << endl;

    return 0;
}
