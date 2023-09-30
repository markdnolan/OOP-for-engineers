//
//  main.cpp
//  chapter3-overloading
//
//  Created by domain_management on 9/25/23.
//
// Overloaded methods
//
/* Using the same method within a C++ class to perform different functions based on the input parameters.
 
 Notice that Derek Molloy uses a different approach to defining classes, he keeps the class definition short by only defining the scope, names and parameters.
 Then builds the implementation of each method below the class definition using the scope resolution operator (::).
 
 Not sure which is the bes approach, look online to see what is most popular in the market...
 */

#include <iostream>
#include <string>

using namespace std;

class MyMaths {
    
public:
    virtual int add(int a, int b);
    virtual float add(float a, float b);
    virtual string add(string a, string b);
};

int MyMaths::add(int a, int b) {
    return (a + b);
}

float MyMaths::add(float a, float b) {
    return (a + b);
}

string MyMaths::add(string a, string b) {
    return (a + b);
}

int main() {
    MyMaths m;
    
    cout << "1 + 2 = " << m.add(1 , 2) << endl;
    cout << "1.5 + 2.0 = " << m.add(1.5f, 2.0f) << endl;
    cout << "one + two = " << m.add("one", "two") << endl;
    
    return 0;
}
