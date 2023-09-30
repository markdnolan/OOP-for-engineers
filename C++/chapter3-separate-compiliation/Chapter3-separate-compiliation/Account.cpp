//
//  Account.cpp
//  Chapter3-separate-compiliation
//
//  Created by domain_management on 9/30/23.
//

#include "Account.hpp"

using namespace std;


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
