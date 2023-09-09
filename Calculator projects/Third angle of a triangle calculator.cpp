#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <cstring>
using namespace std;

int main() {
    //To find the third angle of a triangle = 180 - (angle 1 + angle 2) = angle 3
   
    int angle1;
    int angle2;
    int angle3;
    
    cout << "To find the third angle of a triangle, enter the first and second angles:" << endl;
    
    
    
    if (angle1 <= 180 && angle1 >= 0){
        cout << "Enter the first angle (degrees): " << endl;
        cin >> angle1;
    }
    else if (angle1 >= 180 && angle1 <= 0){
        cout << "Try again. Must enter an angle between 0 and 360 degrees." << endl;
    }
    
    cout << "Enter the second angle (degrees): " << endl;
    if (angle2 >= 180 && angle2 <= 0){
        cout << "Try again. Must enter an angle between 0 and 360 degrees." << endl;
    }
    else if (angle2 <= 180 && angle2 >= 0){
        cin >> angle2;
    }

    cout << "The third angle is: " << (180 - (angle1 + angle2)) << endl;
    
    return 0;
}