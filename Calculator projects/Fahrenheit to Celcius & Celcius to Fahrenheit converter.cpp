#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <cstring>
using namespace std;

int main() {
    //Celcius to farenheit = (celcius * 9/5) + 32
    //Farenheit to celcius = (fahrenheit - 32) * 9/5
   
   int celcius;
   int fahrenheit;
   string input;
   
   cout << "Temperature conversion calculator" << endl;
   cout << "Is your degrees in celcius or fahrenheit? " << endl;
   cin >> input;
   
   if(input != "fahrenheit" || input != "celcius") {
       cout << "Try again" << endl;
   }
       else if (input == "fahrenheit" || input == "celcius"){
           cin >> input;
       }
   
    if (input == "fahrenheit"){
        cout << "Now converting fahrenheit to celcius: " << endl;
        cout << "Enter a temperature in fahrenheit:" << endl;
        cin >> fahrenheit;
        cout << "In celcius that is:  " << ((fahrenheit - 32) * 5/9) << endl;
    }
    
    if (input == "celcius"){
        cout << "Now converting celcius to fahrenheit: " << endl;
        cout << "Enter a temperature in celcius:" << endl;
        cin >> celcius; 
        cout << "In fahrenheit that is:  " << ((celcius * 9/5) + 32) << endl;
    }
    
    return 0;
}