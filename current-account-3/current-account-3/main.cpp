//
//  main.cpp
//  current-account-3
//
//  Created by domain_management on 9/24/23.
//
// Basic Bank Account Example with Constructors.
// Extended with derived class 'Current Account'.
// Added pointers to demonstrate difference between static & dynamic types.

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

    void Account::makeDeposit( float amount){
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
        Account::display();                                                // INCLUDE all the code from the parent method display()
        cout << "And overdraft limit: " << overdraftLimit << endl;    // ADDITIONAL code appended to new method
    }
    
    void CurrentAccount::makeWithdrawl(float amount){
        if (amount < (balance + overdraftLimit)){                    //CurrentAccount INHERITS protected variable balance
            balance = balance - amount;
            }
        }
    
    void CurrentAccount::setOverdraftLimit(float limit){
        overdraftLimit = limit;
        }



int main(){
    Account a = Account(35.00, 794687684);
    Account *ptrA = &a;
    /* pointer to address of "a" object of class "Account".
    understands methods
        - display()
        - makeDeposit()
        - makeWithdrawl()
    */
    
    CurrentAccount b = CurrentAccount(45.00, 12678, 100.00);
    CurrentAccount *ptrB = &b;
    /* pointer to address of "b" object of class "CurrentAccount".
    understands methods
        - display()
        - makeDeposit()
        - makeWithdrawl()
        - setOverdraftLimit()
    */
        
    cout << "Displaying ptrA:" << endl;
    ptrA->display();                    //uses display() method from Account class
    
    cout << "Displaying ptrB:" << endl;
    ptrB->display();                    // uses display() method from CurrentAccount class
    
    //ptrB = ptrA;                         // NOT ALLOWED!
    /* ptrB is of type CurrentAccount
     ptrB understands setOverdraftLimit method
    which isn't defined in Account class
    */
    
    ptrA = ptrB;                        //ALLOWED
    /* ptrA is of type Account
     ptrA understands all the methods defined in class CurrentAccount
    */
    
    cout << "Displaying ptrA again:" << endl;
    ptrA->display();                    // When run this will now execute CurrentAccount display() method.
    // ptrA->setOverdraftLimit(5000);   // ptrA is still of type Account, it can't call methods that are only defined in current account.
}
