
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

Account::Account(float aBalance, int anAccNumber){
	accountNumber = anAccNumber;
	balance = aBalance;
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
	Account anAccount = Account(35.00, 1234); //OK
	Account testAccount(0.0, 1235); // OK
	// Account myAccount = Account(); // Wrong,
	/* This constructor call is not valid as the default constructor 
	is no longer available (the one with no parameters)
	 as a new non-default constructor has been defined.
	*/ 
	
	anAccount.display();
	testAccount.display();
}