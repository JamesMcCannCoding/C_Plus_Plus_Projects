#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

int main()
{
    // Setup random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    // Generate 10 random numbers within 1 – 100 and store directly into the array
    int arr[10];
    for (int i = 0; i < 10; ++i)
    {
        arr[i] = dist(gen);
    }

    // Display the array
    cout << "Original Array:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort the array
    sort(arr, arr + 10);

    // Display the sorted array
    cout << "Sorted Array:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
