//
//  main.cpp
//  chapter3-destructors
//
//  Created by domain_management on 9/30/23.
//
// Basic bank account example demonstrating abstract account classes

#include <iostream>
#include <string>

using namespace std;

class Account {
    
protected:
    
    int accountNumber;
    float balance;
    
public:
    
    Account (float aBalance, int anAccountNumber);
    virtual ~Account();
    virtual string getAccountType() = 0;
    virtual void display();
    virtual void makeDeposit(float);
    virtual void makeWithdrawl(float);
};

Account::Account(float aBalance, int anAccountNumber) {
    cout << "Creating account object!" << endl;
    accountNumber = anAccountNumber;
    balance = aBalance;
}

Account::~Account() {
    
    cout << "Account object being destroyed!" << endl;
}

void Account::display() {
    cout << "Account type: " << getAccountType() << endl;
    cout << "Account number: " << accountNumber
        << " has balance $" << balance << endl;
}

void Account::makeDeposit(float amount) {
    balance = balance + amount;
}

void Account::makeWithdrawl(float amount) {
    balance = balance - amount;
}

class CurrentAccount: public Account {
    
    float overdraftLimit;

public:
    
    CurrentAccount (float balance, int accountNumber, float limit);
    virtual ~CurrentAccount();
    virtual string getAccountType() {
        return "Current Account";
    }
    virtual void setOverdraftLimit(float newLimit);
    virtual void display();
    virtual void makeWithdrawl(float amount);
};

CurrentAccount:: CurrentAccount( float balance, int accountNumber, float limit) :
Account(balance, accountNumber), overdraftLimit(limit) {
    
    cout << "Creating current account object!" << endl;
}

CurrentAccount:: ~CurrentAccount() {
    cout << "Current Account object being destroyed!" << endl;
}

void CurrentAccount::display() {
    Account::display();
    cout << " and overdraft limit: $" << overdraftLimit << endl;
}

void CurrentAccount::makeWithdrawl(float amount) {
    if (amount < (balance + overdraftLimit)) {
        balance = balance - amount;
    }
}

void CurrentAccount::setOverdraftLimit(float limit) {
    overdraftLimit = limit;
}

int main() {
        
    CurrentAccount b = CurrentAccount(50.0, 12345, 200.0);
    cout << "Displaying account." << endl;
    b.display();
    
    return 0;
}
