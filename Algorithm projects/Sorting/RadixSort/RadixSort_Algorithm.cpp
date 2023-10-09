#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

const int SIZE = 20;
const int RANGE = 999;

// Get maximum number from the array to know the number of digits
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Counting sort used in radix sort for sorting based on significant places
void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] contains the actual
    // position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] contains
    // sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort algorithm to sort arr[] of size n
void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    // Do counting sort for every digit
    // Instead of passing digit number, exp is passed
    // exp is 10^i where i is the current digit number
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
        // Print the results of each iteration
        cout << "After sorting on place value 10^" << log10(exp) << ": ";
        for (int i = 0; i < SIZE; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}

int main()
{
    int arr[SIZE];

    // Seed random number generator
    srand(time(NULL));

    // Generate random array of numbers between 1 and 100
    cout << "Original Array: ";
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = 1 + rand() % RANGE; // Random number between 1 and 100
        cout << arr[i] << " ";
    }
    cout << endl;

    // Record start time
    auto start = chrono::high_resolution_clock::now();

    // Sort the array
    radixSort(arr, SIZE);

    // Record end time
    auto stop = chrono::high_resolution_clock::now();

    // Calculate the time difference between start and end in seconds and milliseconds
    auto duration_seconds = chrono::duration_cast<chrono::seconds>(stop - start);
    auto duration_milliseconds = chrono::duration_cast<chrono::milliseconds>(stop - start);

    cout << "Sorted Array: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Time taken to sort: " << duration_seconds.count() << " seconds and ";
    cout << duration_milliseconds.count() << " milliseconds." << endl;

    return 0;
}
