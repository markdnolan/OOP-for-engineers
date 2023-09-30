//
//  main.cpp
//  Chapter3-using-delete-on-arrays-of-objects
//
//  Created by domain_management on 9/30/23.
//

#include <iostream>
#include <string>

using namespace std;

class bird {
    string name;
    
public:
    bird();
    bird(string birdName);
    virtual void display();
};

bird::bird(): name("No name") {
}

bird::bird(string birdName): name(birdName) {
}

void bird::display() {
    cout << "This bird's name is " << name << " ." << endl;
}

int main() {
    
    bird* arrayBirds = new bird[5];
    string names[5] = {"crow", "sparrow", "hawk", "robin", "seagull" };
    
    for (int count = 0; count < 5; count++) {
        arrayBirds[count] = bird(names[count]);
    }
    
    for (int count = 0; count < 5; count++) {
        arrayBirds[count].display();
    }
    
    delete [] arrayBirds; // Destroys the array, note the [], we don't destroy the pointer, we destroy the array.
    
    return 0;
}
