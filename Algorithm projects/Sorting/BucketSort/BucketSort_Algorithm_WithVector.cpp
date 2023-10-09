#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;

// Generate a random number between low and high (inclusive)
int randomRange(int low, int high)
{
    return rand() % (high - low + 1) + low;
}

// Bucket Sort function using vectors
void bucketSort(vector<int> &arr)
{
    int n = arr.size();
    // 1. Create empty buckets
    int max_val = 100;           // maximum possible value
    vector<int> buckets(101, 0); // assuming numbers are between 1 and 100

    // 2. Put vector elements in different buckets based on their value
    for (int i = 0; i < n; i++)
    {
        buckets[arr[i]]++;
    }

    // 3. Sort individual buckets and collect numbers
    int index = 0;
    int iteration = 1; // to keep track of iteration number
    for (int i = 0; i <= max_val; i++)
    {
        while (buckets[i] > 0)
        {
            arr[index++] = i;
            buckets[i]--;

            // Print iteration number and vector after each iteration
            cout << "Iteration " << iteration++ << ": ";
            for (int j = 0; j < n; j++)
            {
                cout << arr[j] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr))); // Seed for random number generation

    vector<int> arr(20);

    // Generate 20 random numbers from 1 to 100
    for (int i = 0; i < 20; i++)
    {
        arr[i] = randomRange(1, 100);
        cout << arr[i] << " ";
    }
    cout << "\nUnsorted Vector\n";

    auto start = chrono::high_resolution_clock::now();
    bucketSort(arr);
    auto stop = chrono::high_resolution_clock::now();

    cout << "\nSorted Vector\n";
    for (int i = 0; i < 20; i++)
    {
        cout << arr[i] << " ";
    }

    auto duration_seconds = chrono::duration_cast<chrono::seconds>(stop - start);
    auto duration_milliseconds = chrono::duration_cast<chrono::milliseconds>(stop - start);

    cout << "\nTime taken to sort: " << duration_seconds.count() << " seconds" << endl;
    cout << "Time taken to sort: " << duration_milliseconds.count() << " milliseconds" << endl;

    return 0;
}
