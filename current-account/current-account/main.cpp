//
//  main.cpp
//  current-account
//
//  Created by domain_management on 9/24/23.
//
// Basic Bank Account Example with Constructors

#include<iostream>

using namespace std;

class Account{

    protected:                //NOTE: Changed from private to protected so that they are visible to child class

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
        accountNumber(anAccNumber), balance (aBalance){ // sets states
        
        // anything else place here
    
        }

    void Account::display(){
        cout << "Account number: " << accountNumber
            << " has balance: " << balance << " Dollars." << endl;
    }

    void Account::makeDeposit(float amount){
        balance = balance + amount;
    }

    void Account::makeWithdrawl(float amount){
        balance = balance - amount;
    }

class CurrentAccount: public Account{
        float overdraftLimit;                                        //ADDITIONAL public variable
    
    public:
        CurrentAccount(float bal, int actNum, float limit);            // CurrentAccount constructor method OVERRIDES Account
        virtual void setOverdraftLimit(float newLimit);                // ADDITIONAL methods declared
        virtual void display();                                        // OVERRIDE method display()
        virtual void makeWithdrawl(float amount);                    // OVERRIDE method display()
    };
    
    CurrentAccount::CurrentAccount(float bal, int accNum, float limit):        // NEW constructor
        Account(bal, accNum), overdraftLimit(limit){
        }

    void CurrentAccount::display(){
        cout << "Account number: " << accountNumber                    //CurrentAccount INHERITS protected variable accountNumber
            << " has balance: " << balance << " Dollars." << endl;    //CurrentAccount INHERITS protected variable balance
        cout << "And overdraft limit: " << overdraftLimit << endl;
    }
    
    void CurrentAccount::makeWithdrawl(float amount){
        if (amount < (balance + overdraftLimit)){
            balance = balance - amount;
            }
        }
    
    void CurrentAccount::setOverdraftLimit(float limit){
        overdraftLimit = limit;
        }



int main(){
    Account anAccount = Account(35.00, 1234); //OK
    Account testAccount(0.0, 1235); // OK
        
    anAccount.display();
    anAccount.makeDeposit(50.00);
    anAccount.display();
    testAccount.display();
    
    CurrentAccount aCurrentAccount = CurrentAccount(45.00, 12678, 100.00);
    aCurrentAccount.display();
    aCurrentAccount.makeDeposit(55.00);
    aCurrentAccount.display();
    aCurrentAccount.makeWithdrawl(150.00);
    aCurrentAccount.display();
    aCurrentAccount.makeWithdrawl(100.00);
    aCurrentAccount.display();
    aCurrentAccount.setOverdraftLimit(200.00);
    aCurrentAccount.display();
    aCurrentAccount.makeWithdrawl(100.00);
    aCurrentAccount.display();
    aCurrentAccount.makeDeposit(200.00);
    aCurrentAccount.display();
    
}
