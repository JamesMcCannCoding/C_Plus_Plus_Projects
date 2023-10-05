#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <iomanip>

using namespace std;

void printVector(const vector<int> &vec)
{
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;
}

int partition(vector<int> &vec, int low, int high, int &iteration)
{
    int pivot = vec[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (vec[j] <= pivot)
        {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);

    cout << "Iteration " << ++iteration << ": ";
    printVector(vec);

    return i + 1;
}

void quickSort(vector<int> &vec, int low, int high, int &iteration)
{
    if (low < high)
    {
        int pi = partition(vec, low, high, iteration);

        // Recursively sort the elements
        quickSort(vec, low, pi - 1, iteration);
        quickSort(vec, pi + 1, high, iteration);
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<int> vec(20);
    for (int i = 0; i < 20; i++)
    {
        vec[i] = 1 + rand() % 100; // Random number between 1 and 100
    }

    cout << "Unsorted vector: ";
    printVector(vec);

    int iteration = 0;

    auto start_time = chrono::high_resolution_clock::now();

    quickSort(vec, 0, vec.size() - 1, iteration);

    auto end_time = chrono::high_resolution_clock::now();
    double elapsed_seconds = chrono::duration<double, std::ratio<1>>(end_time - start_time).count();
    auto elapsed_milliseconds = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    cout << "Sorted vector: ";
    printVector(vec);

    cout << fixed << setprecision(5);
    cout << "Time taken to sort: " << elapsed_seconds << " seconds or "
         << elapsed_milliseconds.count() << " milliseconds" << endl;

    return 0;
}
