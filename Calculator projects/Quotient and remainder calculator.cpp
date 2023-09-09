#include <iostream>
using namespace std;

int main() {

    	int dividend, divisor, quotient,remainder;
    	
		cout << "Calculator to compute quotient and remainder\n";
		cout << "--------------------------------------------\n";		
        
        cout << "Input the dividend : \n";
    	cin >> dividend;
    	
        cout << "Input the divisor : \n";
    	cin >> divisor;
    	
		quotient = dividend / divisor;
		
		remainder = dividend % divisor;
		
        cout << "The quotient of the division is : " << quotient << endl;
        cout << "The remainder of the division is : " << remainder << endl;
        cout << endl;

    return 0;
}