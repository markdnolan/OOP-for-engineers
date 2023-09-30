//
//  main.cpp
//  constant-parameters
//
//  Created by domain_management on 9/24/23.
// Constant parameters.

#include <iostream>

using namespace std;

// NOTE: aValue passed by reference, it's x not a copy of x for the function!
void decrement(const int &aValue, int amount = 1) {
//    aValue = aValue - amount;     // ERROR: Cannot assign to variable 'aValue' with const-qualified type 'const int &'
}

int main() {
    
    int x = 10;
    decrement( x, 3);   // x now has value 7
    cout << "x now has value: " << x << endl;
    decrement( x);  // x now has value 6.
    cout << "x now has the value: " << x << endl;
    
    return 0;
}
