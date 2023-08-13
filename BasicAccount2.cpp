
// Basic Bank Account Example

#include<iostream>

using namespace std;

class Account{

private:

	int accountNumber;
	float balance;
	
public:

	virtual void display();
	virtual void makeDeposit(float);
	virtual void makeWithdrawl(float);
};

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
	Account myAccount;
	
	cout << "Account details:";
	myAccount.display();
	
	myAccount.makeDeposit(2300.00);
	cout << "Account details: ";
	myAccount.display();
	
	//myAccount.balance = 2300.00; //Wrong!
	/* The balance state is a private state of the Account class, 
	so you cannot modify it directly. It is not part of the interface.
	*/
	
	//cout << "Account balance: " << myAccount.balance << endl; // Wrong!
	/* The balance state is not part of the interface 
	and does not even allow the value to be read.
	*/
}