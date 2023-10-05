#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

const int VECTOR_SIZE = 15;

// Function to print the vector
void printVector(const vector<int> &vec)
{
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Function to perform selection sort on a vector
void selectionSort(vector<int> &vec)
{
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        size_t min_index = i;
        for (size_t j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(vec[i], vec[min_index]);
        }

        // Print the vector after each iteration
        cout << "After iteration " << (i + 1) << ": ";
        printVector(vec);
    }
}

int main()
{
    vector<int> vec;

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate random numbers and fill the vector
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        vec.push_back(1 + rand() % 100); // Generates a number between 1 and 100
    }

    cout << "Original vector: ";
    printVector(vec);

    // Record the start time
    auto start = chrono::high_resolution_clock::now();

    // Sort the vector
    selectionSort(vec);

    // Record the end time
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsed = end - start;
    int elapsedMillis = static_cast<int>(elapsed.count() * 1000);

    cout << "Sorted vector: ";
    printVector(vec);

    cout << "Time taken to sort: " << elapsed.count() << " seconds (" << elapsedMillis << " milliseconds)." << endl;

    return 0;
}
