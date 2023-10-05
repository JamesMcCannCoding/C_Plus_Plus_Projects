#include <iostream>
#include <chrono>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)         // This Outter loop will be used for making length number of passes.
    {                                       // -1 to go up to the second last index of the array. Not the last becasue there is nothing to compare it with (cannot compare to the right of it).
        for (int j = 0; j < n - i - 1; j++) // Inner array will be swapping numbers next to each other (doing the sorting).
        {
            if (arr[j] > arr[j + 1]) // If element j is greater than element j to its right, then swap them.
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; // temp variable is a place-holder.
            }
        }
        // Print the array after each iteration:
        cout << "After iteration " << i + 1 << ": " << endl;
        for (int k = 0; k < n; k++)
            cout << arr[k] << " ";
        cout << endl;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 64, 34, 25, 12, 22, 11, 90, 99, 91, 63, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: " << endl;
    printArray(arr, n);

    // Timing starts
    auto start = chrono::high_resolution_clock::now();

    bubbleSort(arr, n);

    // Timing ends
    auto end = chrono::high_resolution_clock::now();

    cout << "After sorting: " << endl;
    printArray(arr, n);

    chrono::duration<double> elapsed_seconds = end - start;
    auto elapsed_milliseconds = chrono::duration_cast<chrono::milliseconds>(elapsed_seconds);

    cout << "Time taken to sort: " << elapsed_seconds.count() << " seconds" << endl;
    cout << "Time taken to sort: " << elapsed_milliseconds.count() << " milliseconds" << endl;

    return 0;
}
