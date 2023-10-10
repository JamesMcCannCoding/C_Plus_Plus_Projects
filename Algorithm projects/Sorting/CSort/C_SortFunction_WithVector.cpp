#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main()
{
    // Setup random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    // Directly create a vector of 10 elements and populate them with random numbers
    vector<int> v(10);
    for (int i = 0; i < 10; ++i)
    {
        v[i] = dist(gen);
    }

    // Display the vector
    cout << "Original Vector:" << endl;
    for (int num : v)
    {
        cout << num << " ";
    }
    cout << endl;

    // Sort the vector
    sort(v.begin(), v.end());

    // Display the sorted vector
    cout << "Sorted Vector:" << endl;
    for (int num : v)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
