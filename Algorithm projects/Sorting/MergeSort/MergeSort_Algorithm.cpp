#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

const int SIZE = 20;

int iterationNumber = 0;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    cout << "Iteration " << ++iterationNumber << ": ";
    printArray(arr, SIZE);
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main()
{
    srand(time(0));

    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = 1 + rand() % 100;
    }

    cout << "Unsorted array:" << endl;
    printArray(arr, SIZE);
    cout << "\nSorting iterations:" << endl;

    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, SIZE - 1);
    auto stop = chrono::high_resolution_clock::now();

    cout << "\nSorted array:" << endl;
    printArray(arr, SIZE);

    auto duration_seconds = chrono::duration_cast<chrono::seconds>(stop - start);
    auto duration_milliseconds = chrono::duration_cast<chrono::milliseconds>(stop - start);

    cout << "\nTime taken by function: "
         << duration_seconds.count() << " seconds"
         << " or " << duration_milliseconds.count() << " milliseconds" << endl;

    return 0;
}