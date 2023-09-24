//
//  main.cpp
//  current-account-4
//
//  Created by domain_management on 9/24/23.
//
// Extended with derived class 'Current Account'.
// Added pointers to demonstrate difference between static & dynamic types.
// Added new "getAccountType" method to demonstrate use of abstract methods.

#include<iostream>
#include<string>

using namespace std;

class Account{

    protected:
                    
        int accountNumber;
        float balance;
    
    public:

        Account(float aBalance, int anAccNumber);
        virtual string getAccountType() = 0;        // NEW ABSTRACT METHOD
        
        /* The assignment of "= 0" allows the method to be defined as abstract.
        This means that no implementation will be present for that method,
        in this case the  getAccountType() method.
        */
        
        virtual void display();
        virtual void makeDeposit(float);
        virtual void makeWithdrawl(float);
};

    
Account::Account(float aBalance, int anAccNumber):
    accountNumber(anAccNumber), balance (aBalance){
    }

void Account::display(){
    cout << "Account type: " << getAccountType() <<endl;        // CALL TO ABSTRACT METHOD
        
    /*
    Even thought there is no actual implementation for the getAccountType() method,
    it can still be used. Since the class has an abstract method,
    the entire class is abstract and so cannot be instantiated,
    so no objects can now be created of the  Account class.
    To use this class, a child class must exist
    and it must implement the getAccountType() method
    before an object can be created of that class.
    */
        
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
        float overdraftLimit;
    
    public:
    
        CurrentAccount(float bal, int actNum, float limit);
        virtual string getAccountType();                    // CHILD CLASS DEFINES ABSTRACT METHOD
        
        /* The abstract method getAccountType() must be re-defined in the child class.
        Note that this time there is no " = 0",
        stating that there will be an implementation in this class f
        or the defined method.
        */
                
        virtual void setOverdraftLimit(float newLimit);
        virtual void display();
        virtual void makeWithdrawl(float amount);
};
    
CurrentAccount::CurrentAccount(float bal, int accNum, float limit):
    Account(bal, accNum), overdraftLimit(limit){
    }
    
string CurrentAccount::getAccountType(){                // NEW METHOD
    return "Current Account";
}
        
        /* The implementation is coded.
        For this class all that occurs is that the string "Current Account"
        is returned from the method.
        The implementation for a deposit account would return "Deposit Account" etc.
        */

void CurrentAccount::display(){
    Account::display();                                    // INCORPORATES CALL TO ABSTRACT METHOD
    
    /* The Account::display() method is called in the same way as before,
    so the display() method of the parent is used,
    which in turn calls the  getAccountType() method of the child class.
    */
        
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

    // Account a = Account(35.00, 794687684);  //NOT ALLOWED, "Account" class includes abstract method, can't be called.
    // .Account *ptrA = &a;
    
    CurrentAccount b = CurrentAccount(45.00, 12678, 100.00);
    b.display();
    
    /* The call to b.display() calls the display method of  CurrentAccount,
    which in turn calls the display() method of the parent Account class.
    */
    
}
