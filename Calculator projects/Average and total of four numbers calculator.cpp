#include <iostream>
using namespace std;

int main() {

    float n1, n2, n3, n4, total, average;
    
    cout << "--- Calculate the total and average for input numbers --- \n";
    
    cout << "Input the first two numbers (seperated by space): \n";
        cin >> n1 >> n2;
    cout << "Input the second two numbers (seperated by space): \n";
        cin >> n3 >> n4;
  
    total = n1 + n2 + n3 + n4;
    average = total / 4;

    cout << "The total of the four numbers is: " << total << endl;
    cout << "The average of the four numbers is: " << average << endl;

    return 0;
}