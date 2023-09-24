//
//  main.cpp
//  basic-account-with-pointers
//
//  Created by domain_management on 9/24/23.
//
// Basic Bank Account Example with Constructors

#include<iostream>

using namespace std;

class Account{

private:

    int accountNumber;
    float balance;
    
public:

    Account(float, int);
    virtual void display();
    virtual void makeDeposit(float);
    virtual void makeWithdrawl(float);
};

// The constructor code implementation.
Account::Account(float aBalance, int anAccNumber): // note :
    accountNumber(anAccNumber), balance (aBalance) // sets states
    {
    // anything else place here
    
}

void Account::display(){
    cout << "Account number: " << accountNumber
        << " has balance: " << balance << " Dollars." << endl;
}

void Account::makeDeposit( float amount){
    balance = balance + amount;
}

void Account::makeWithdrawl(float amount){
    balance = balance - amount;
}

int main(){
    //object notation
    Account anAccount = Account(35.00, 12344);
    anAccount.makeDeposit(20.0);
    anAccount.display();
    
    //pointer notation
    Account testAccount = Account(0.0, 12345);
    Account *testPtr = &testAccount; //pointer testPtr holds the address of testAccount object
    testPtr->makeDeposit(20.0);
    testPtr->display();
    /* Note that testPtr->myBalance is exactly the same as (*testPtr).myBalance,
    but the -> notation is a lot easier to comprehend when combined with other operators.
    */
    
    Account anotherTest = Account( 21.45, 67892), *anPtr;
    anPtr = &anotherTest;
    
    anPtr -> display();
    
    Account nextAccount(45.63, 33333);
    Account *nextPtr = &nextAccount;
    nextPtr -> display();
    
}
