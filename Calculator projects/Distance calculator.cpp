#include <iostream>
using namespace std;
 
struct distance{
    int meters;
    float centimeters;
}
distance1 , distance2, add;
 
int main()
{
    cout <<"Please enter first distance: " << endl;
    
	cout << "Please enter meters: ";
    cin >> distance1.meters;
    
    cout << "Please enter centimeters: ";
    cin >> distance1.centimeters;
 
    cout << endl <<"Pleas enter second distance: " << endl;
   
    cout << "Please enter meters: ";
    cin >> distance2.meters;
   
    cout << "Please enter centimeters: ";
    cin >> distance2.centimeters;
 
    add.meters = distance1.meters + distance2.meters;
    add.centimeters = distance1.centimeters + distance2.centimeters;
 
    cout << "The sum of distances= " << add.meters << " meters  " << add.centimeters << " centimeters" << endl;
    return 0;
}