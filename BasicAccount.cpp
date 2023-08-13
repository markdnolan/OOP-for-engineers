
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
	Account a;
	a.display();		//will output rubbish for the states
}