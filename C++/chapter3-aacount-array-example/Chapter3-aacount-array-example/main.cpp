//
//  main.cpp
//  Chapter3-aacount-array-example
//
//  Created by domain_management on 9/30/23.
//
// Basic bank account demonstrating creation of arrays of objects
#include <iostream>
#include <string>

using namespace std;

class Account {
    
protected:
    
    int accountNumber;
    float balance;
    string owner;
    
public:
    
    Account (string owner, float aBalance, int anAccountNumber);
    Account (float aBalance, int anAccountNumber);
    Account (int anAccountNumber);
    
    virtual void display();
    virtual void makeDeposit(float);
    virtual void makeWithdrawl(float);
};

Account::Account(string anOwner, float aBalance, int anAccountNumber) :
    accountNumber(anAccountNumber), balance(aBalance), owner(anOwner) {
}

Account::Account(float aBalance, int anAccountNumber) :
    accountNumber(anAccountNumber), balance(aBalance),
    owner("Not defined.") {
}

Account::Account( int anAccountNumber) :
    accountNumber(anAccountNumber), balance(0.0f),
    owner("Not defined.") {
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
    Account someAccounts[3] = {
        Account("Tom", 20.00, 123456),
        Account("Dick", 55.00, 123457),
        Account("Harry", 99.00, 123458)
    };
    
    Account *p = &someAccounts[0];
    
    someAccounts[2].display();   // Displays Harry
    
    p->display(); // Dipslays Tom.
    (++p)->display();    // Displays Dick.
    (p+1)->display();   //Displays harry.
    
    //Warning! The pointer p now points at Richard, not Tom!
    
    Account *q = &someAccounts[0];
    for (int count=0; count < 3; ++count) {
        (q + count)->display();
    }
    
    return 0;
}
