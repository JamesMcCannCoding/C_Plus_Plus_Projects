#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;

// Function to perform shell sort on the array
void shellSort(int arr[], int n)
{
    // Start with a large gap, then reduce the gap
    int iteration = 1; // To keep track of the iteration number
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        // Print the iteration number and the array after each iteration
        cout << "Iteration " << iteration << ": ";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
        iteration++;
    }
}

int main()
{
    int arr[20];

    // Seed the random number generator with current time
    srand(time(0));

    // Generate 20 random numbers in the range 1 to 100
    for (int i = 0; i < 20; i++)
    {
        arr[i] = 1 + rand() % 100;
    }

    // Print the unsorted array
    cout << "Unsorted array:" << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;

    // Start the clock to measure time
    auto start = chrono::high_resolution_clock::now();

    // Perform shell sort
    shellSort(arr, 20);

    // Stop the clock
    auto stop = chrono::high_resolution_clock::now();

    // Calculate the duration in seconds and milliseconds
    auto durationSeconds = chrono::duration_cast<chrono::seconds>(stop - start);
    auto durationMilliseconds = chrono::duration_cast<chrono::milliseconds>(stop - start);

    // Print the sorted array
    cout << "Sorted array:" << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print the time taken to sort the array
    cout << "Time taken to sort: " << durationSeconds.count() << " seconds (or "
         << durationMilliseconds.count() << " milliseconds)" << endl;

    return 0;
}
