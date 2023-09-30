//
//  main.cpp
//  Chapter3-AccountDynamicCreationTest
//
//  Created by domain_management on 9/30/23.
//
// Basic bank account demonstrating dynamic creation of objects

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
    virtual ~Account();
    
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

Account::~Account() {
    cout << "Account with owner " << owner << " has just been destroyed." << endl;
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
        
    Account *a = new Account("John", 10.5, 123456);
    Account *b = new Account("Mark", 35.50, 123457);
    
    a-> display();
    b-> display();
    
    b = a;  // Here we lose the pointer to "a" (a & b point to the same location), no way to destroy - memopry leak!
    
    a-> display();
    b-> display();
    
    delete a;   // Deletes John's account
    // delete b;   // Tries to delete John's account again - Thread 1: EXC_BAD_ACCESS (code=1, address=0xbeadde6d4b78)
    
    return 0;
}
