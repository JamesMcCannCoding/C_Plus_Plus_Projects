#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <vector>

using namespace std;

const int SIZE = 20;
const int RANGE = 999;

// Get maximum number from the vector to know the number of digits
int getMax(const vector<int> &v)
{
    int max = v[0];
    for (int num : v)
        if (num > max)
            max = num;
    return max;
}

// Counting sort used in radix sort for sorting based on significant places
void countSort(vector<int> &v, int exp)
{
    int n = v.size();
    vector<int> output(n);
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(v[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(v[i] / exp) % 10] - 1] = v[i];
        count[(v[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        v[i] = output[i];
}

void radixSort(vector<int> &v)
{
    int max = getMax(v);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(v, exp);
        cout << "After sorting on place value 10^" << log10(exp) << ": ";
        for (int num : v)
            cout << num << " ";
        cout << endl;
    }
}

int main()
{
    vector<int> v;

    srand(time(NULL));

    cout << "Original Vector: ";
    for (int i = 0; i < SIZE; i++)
    {
        v.push_back(1 + rand() % RANGE);
        cout << v[i] << " ";
    }
    cout << endl;

    auto start = chrono::high_resolution_clock::now();

    radixSort(v);

    auto stop = chrono::high_resolution_clock::now();

    auto duration_seconds = chrono::duration_cast<chrono::seconds>(stop - start);
    auto duration_milliseconds = chrono::duration_cast<chrono::milliseconds>(stop - start);

    cout << "Sorted Vector: ";
    for (int num : v)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Time taken to sort: " << duration_seconds.count() << " seconds and ";
    cout << duration_milliseconds.count() << " milliseconds." << endl;

    return 0;
}
