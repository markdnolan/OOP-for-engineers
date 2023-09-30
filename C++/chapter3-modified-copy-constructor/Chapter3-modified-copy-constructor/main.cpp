//
//  main.cpp
//  Chapter3-modified-copy-constructor
//
//  Created by domain_management on 9/30/23.
//

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
    Account(const Account &sourceAccount);  // Copy constructor.
    
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

Account::Account(const Account &sourceAccount):
    accountNumber(sourceAccount.accountNumber +1),
    balance(0.0f),
    owner(sourceAccount.owner) {
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
        
    Account a = Account("Mark Nolan", 35.00, 123457);
    Account b(a);
    
    a.display();
    b.display();    // Copy constructor increments account number & resets balance to $0.00.
    
    a.makeDeposit(100.0);
    
    a.display();    // Account a now has a balance of $135.00.
    b.display();    // Account b still has the initial balance of $0.00.
    
    return 0;
}
