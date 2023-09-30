//
//  main.cpp
//  Chapter3-static-member-test
//
//  Created by domain_management on 9/30/23.
//
//  Static member example
// Basic bank account demonstrating multiple constructors

#include <iostream>
#include <string>

using namespace std;

class Account {
    
protected:
    
    static int nextAccountNumber;   // Declare "nextAccountNumber" as static.
    int accountNumber;
    float balance;
    string owner;
    
private:
    
    void construct();
    
public:
    
    Account (string owner, float aBalance);
    Account (float aBalance);
    
    virtual void display();
    virtual void makeDeposit(float);
    virtual void makeWithdrawl(float);
};

/*  C++ requiures us to define and set a value to a static in the implemetatioon of the class.
    NOTE: The static keyword isn't used again.
 */
int Account::nextAccountNumber = 123456;

//  Multiple constructors
Account::Account(string anOwner, float aBalance) :
    balance(aBalance), owner(anOwner) {
        construct();          // Can't call one constructor from another.
}

Account::Account(float aBalance) :
    balance(aBalance),
    owner("Not defined.") {
        construct();    // Can't call one constructor from another.
}

/*  Can't call one constructor from another so create a priovate method containing common code to all constructors and then call it form every constructor. This allows you to easily update all constructors with changes to common code.
 
    The private construct() method sets the accountNumber state to the nextAccountNumber and increments the
    nextAccountNumber after the assignment. 
    Since the static state is shared with every Account object it is incremented on each and every object. 
    This means that when every object is created it will have its own individual account number,
    without having to pass the value to the constructor.
 */
void Account::construct() {
    accountNumber = nextAccountNumber++;
}

void Account::display() {
    cout << "Account number: " << accountNumber
        << " has balance $" << balance << endl;
    cout << "This account is owned by: " << owner << endl;
}

void Account::makeDeposit(float amount) {
    balance = balance + amount;
}

void Account::makeWithdrawl(float amount) {
    balance = balance - amount;
}

int main() {
        
    Account *a = new Account("John Doe", 10.50);
    Account *b = new Account("Mark Nolan", 35.50);
    
    a->display();
    b->display();
    
    return 0;
}

