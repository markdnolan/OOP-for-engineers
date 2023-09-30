//
//  Account.hpp
//  Chapter3-separate-compiliation
//
//  Created by domain_management on 9/30/23.
//

#include <iostream>
#include <string>

using std::string;  // Only string is required.

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
