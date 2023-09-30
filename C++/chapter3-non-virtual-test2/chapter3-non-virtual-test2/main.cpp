//
//  main.cpp
//  chapter3-non-virtual-test2
//
//  Created by domain_management on 9/30/23.
// Basic bank account demonstrating NON-VIRTUAL methods

#include <iostream>
#include <string>

using namespace std;

class Account {
    
public:
    
    string getType() {
        return "Generic account.";
    }
};

class Current: public Account {
    
public:
    
    string getType() {
        return "Current account.";
    }
};

class Deposit: public Account {
    
public:
    string getType() {
        return "Deposit account.";
    }
};


int main() {
        
    Account *a = new Account();
    Account *b = new Current();
    Account *c = new Deposit();
    
    /* The pointers a, b & c are ALL of type Account so the getType method of
     class "Account" is always called.
     */
        
    cout << "Pointer a displayed: " << a->getType() << endl;
    cout << "Pointer b displayed: " << b->getType() << endl;
    cout << "Pointer c displayed: " << c->getType() << endl;
    
    return 0;
}
