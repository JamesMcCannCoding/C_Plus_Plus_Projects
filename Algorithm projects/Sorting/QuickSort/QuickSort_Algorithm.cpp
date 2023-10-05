#include <iostream>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int ARRAY_SIZE = 20;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int low, int high, int &iteration)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    cout << "Iteration " << ++iteration << ": ";
    printArray(arr, ARRAY_SIZE);

    return i + 1;
}

void quickSort(int arr[], int low, int high, int &iteration)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, iteration);

        // Recursively sort the elements
        quickSort(arr, low, pi - 1, iteration);
        quickSort(arr, pi + 1, high, iteration);
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    int arr[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = 1 + rand() % 100; // Random number between 1 and 100
    }

    cout << "Unsorted array: ";
    printArray(arr, ARRAY_SIZE);

    int iteration = 0;

    auto start_time = chrono::high_resolution_clock::now();

    quickSort(arr, 0, ARRAY_SIZE - 1, iteration);

    auto end_time = chrono::high_resolution_clock::now();
    double elapsed_seconds = chrono::duration<double, std::ratio<1>>(end_time - start_time).count();
    auto elapsed_milliseconds = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    cout << "Sorted array: ";
    printArray(arr, ARRAY_SIZE);

    cout << fixed << setprecision(5);
    cout << "Time taken to sort: " << elapsed_seconds << " seconds or "
         << elapsed_milliseconds.count() << " milliseconds" << endl;

    return 0;
}
