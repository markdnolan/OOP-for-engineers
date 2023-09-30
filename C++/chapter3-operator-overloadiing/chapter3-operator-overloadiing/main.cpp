//
//  main.cpp
//  chapter3-operator-overloadiing
//
//  Created by domain_management on 9/25/23.
//
// Operator overloaded account example.

#include <iostream>
#include <string>

using namespace std;

class Account {
    
protected:
    int accountNumber;
    float balance;
    string owner;
    
public:
    
    Account(string owner, float aBalance, int anAccountNumber);
    Account(float aBalance, int anAccountNumber);
    Account(int anAccountNumber);
    
    Account operator + (Account);
    bool operator == (Account);
    
    virtual void display();
    virtual void makeDeposit(float);
    virtual void makeWithdrawl(float);
};

// Overloaded constructors:

Account::Account(string anOwner, float aBalance, int anAccNumber) :
    accountNumber(anAccNumber), balance(aBalance),
    owner(anOwner) {};

Account::Account(float aBalance, int anAccountNumber) :
    accountNumber(anAccountNumber), balance(aBalance),
    owner("Not defined") {};

Account::Account(int anAccNumber) :
    accountNumber(anAccNumber), balance(0.0f),
    owner("Not defined") {};

Account Account::operator + (Account temp) {
    // "Account temp" is the RHS of the addition statement.
    // "Account *this" is the LHS of the additina statement.
    Account* temp_ptr = &temp;
    cout << temp_ptr->balance << endl;
    cout << temp.balance << endl;
    cout << this->balance << endl;
    return Account(owner, balance + temp.balance, accountNumber);
}

bool Account::operator == (Account a) {
    if ((a.balance == balance) && (a.owner == owner) && (a.accountNumber == accountNumber)) {
        return true;
    }
    else
        return false;
}

void Account::display() {
    cout << "Account number: " << accountNumber << endl;
    cout << "has a balance of: $" << balance << endl;
    cout << "The account holder's name is: " << owner << endl;
}

void Account::makeDeposit(float amount) {
    balance = balance + amount;
}

void Account::makeWithdrawl(float amount) {
    balance = balance - amount;
}

int main() {
    
    Account a = Account(10.50, 123456);
    a.display();
    
    Account b = Account( "Mark Nolan", 35.50, 123457);
    b.display();
    
    Account c = Account( "Mark Nolan", 35.50, 123457);
    if (b == c) {
        cout << "b and c are equal!" << endl;
    }
    
    Account d = b + a;
    d.display();
    
    return 0;
}
