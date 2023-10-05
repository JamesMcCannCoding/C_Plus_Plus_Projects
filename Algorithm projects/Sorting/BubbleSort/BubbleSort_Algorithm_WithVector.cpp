#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void printVector(const vector<int> &vec)
{
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int> &vec)
{
    int n = vec.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                // Swap the elements
                swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        cout << "After iteration " << i + 1 << ": ";
        printVector(vec);

        // If no two elements were swapped in the inner loop, the list is already sorted
        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    vector<int> numbers = {34, 12, 56, 78, 90, 23, 44, 56, 89, 22,
                           11, 45, 86, 58, 33, 99, 15, 61, 76, 49};

    cout << "Original vector: ";
    printVector(numbers);

    // Start timing
    auto start = chrono::high_resolution_clock::now();

    bubbleSort(numbers);

    // End timing
    auto end = chrono::high_resolution_clock::now();

    cout << "Sorted vector: ";
    printVector(numbers);

    chrono::duration<double> diff = end - start;
    cout << "Time taken to sort: " << diff.count() << " seconds" << endl;

    return 0;
}
