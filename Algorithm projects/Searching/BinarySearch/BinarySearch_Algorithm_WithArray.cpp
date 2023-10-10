#include <iostream>
#include <chrono> // For measuring time duration

using namespace std;
using namespace std::chrono; // For using duration_cast and related functions

// Function to perform binary search on an array
int binarySearch(int arr[], int n, int x)
{
    int l = 0;     // Left boundary of the search
    int r = n - 1; // Right boundary of the search

    while (l <= r)
    {
        int mid = l + (r - l) / 2; // Calculate mid point of current search range

        // If x is present at mid, return the index
        if (arr[mid] == x)
        {
            return mid;
        }

        // If x is greater, ignore the left half
        if (arr[mid] < x)
        {
            l = mid + 1;
        }
        // If x is smaller, ignore the right half
        else
        {
            r = mid - 1;
        }
    }
    // Element was not found
    return -1;
}

int main()
{
    int arr[20] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200};

    // Printing the array on screen
    cout << "Array: ";
    for (int i = 0; i < 20; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Capturing the start time before the search
    auto start_time = high_resolution_clock::now();

    int index = binarySearch(arr, 20, 180); // Searching for 180 in the array using binary search

    // Capturing the end time after the search
    auto end_time = high_resolution_clock::now();

    // Calculating the time taken for the search in milliseconds
    auto duration_milliseconds = duration_cast<milliseconds>(end_time - start_time).count();

    // Calculating the time taken for the search in seconds
    double duration_seconds = duration_milliseconds / 1000.0;

    if (index != -1)
    {
        cout << "Number 180 found at index: " << index << endl;
    }
    else
    {
        cout << "Number 180 not found in the array." << endl;
    }

    // Printing the search time in seconds and milliseconds
    cout << "Time taken to search: " << duration_seconds << " seconds" << endl;
    cout << "Time taken to search: " << duration_milliseconds << " milliseconds" << endl;

    return 0;
}
