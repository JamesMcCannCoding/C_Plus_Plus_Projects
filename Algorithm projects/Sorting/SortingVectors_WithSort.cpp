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

    // Generate 10 random numbers within 1 – 100
    vector<int> randomNumbers;
    for (int i = 0; i < 10; ++i)
    {
        randomNumbers.push_back(dist(gen));
    }

    // Ask user for vector size
    int size;
    cout << "Enter size of the vector: ";
    cin >> size;

    if (size < 10)
    {
        cout << "Size should be at least 10 to populate with the 10 random numbers." << endl;
        return 1;
    }

    // Create the vector v of specified size and populate the first 10 elements with random numbers
    vector<int> v(size);
    for (int i = 0; i < 10; ++i)
    {
        v[i] = randomNumbers[i];
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
