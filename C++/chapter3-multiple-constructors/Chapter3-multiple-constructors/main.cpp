//
//  main.cpp
//  Chapter3-multiple-constructors
//
//  Created by domain_management on 9/30/23.
//
// Basic bank account demonstrating multiple constructors

#include <iostream>
#include <string>

using namespace std;

class Account {
    
protected:
    
    int accountNumber;
    float balance;
    string owner;
    
public:
    
    // Multiple constructors
    Account (string owner, float aBalance, int anAccountNumber);
    Account (float aBalance, int anAccountNumber);
    Account (int anAccountNumber);
    
    virtual void display();
    virtual void makeDeposit(float);
    virtual void makeWithdrawl(float);
};

// Multiple constructor definitions follow:

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
        
    Account a = Account(10.5, 123456);
    a.display();
    
    Account b = Account("Mark Nolan", 35.50, 123457);
    b.display();
    
    return 0;
}
