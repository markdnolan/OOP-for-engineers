//
//  main.cpp
//  default-parameters
//
//  Created by domain_management on 9/24/23.
//
// Default parameters.

#include <iostream>

using namespace std;

// NOTE: aValue passed by reference, it's x not a copy of x for the function!
void decrement(int &aValue, int amount = 1) {
    aValue = aValue - amount;
}

int main() {
    
    int x = 10;
    decrement( x, 3);   // x now has value 7
    cout << "x now has value: " << x << endl;
    decrement( x);  // x now has value 6.
    cout << "x now has the value: " << x << endl;
    
    return 0;
}
