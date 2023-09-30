//
//  main.cpp
//  chapter3-non-virtual-test
//
//  Created by domain_management on 9/30/23.
//
// Basic bank account demonstrating VIRTUAL methods

#include <iostream>
#include <string>

using namespace std;

class Account {
    
public:
    
    virtual string getType() {
        return "Generic account.";
    }
};

class Current: public Account {
    
public:
    
    virtual string getType() {
        return "Current account.";
    }
};

class Deposit: public Account {
    
public:
    virtual string getType() {
        return "Deposit account.";
    }
};


int main() {
        
    Account *a = new Account();
    Account *b = new Current();
    Account *c = new Deposit();
    
    /* The pointers a, b & c are ALL of type Account but the "getType methods are virtual
     so the getType method  MOST CLOSELY ASSOCIATED WITH THE OBJECT is called.
     */
    
    cout << "Pointer a displayed: " << a->getType() << endl;
    cout << "Pointer b displayed: " << b->getType() << endl;
    cout << "Pointer c displayed: " << c->getType() << endl;
    
    return 0;
}
