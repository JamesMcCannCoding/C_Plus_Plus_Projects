#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
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

    bubbleSort(arr, n);

    cout << "After sorting: " << endl;
    printArray(arr, n);

    return 0;
}