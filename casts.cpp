
// Start reading from main() function to help make it easier to understand

#include<iostream>

using namespace std;

// Demo classes with a virtual base class

class Account{
	public:
		float balance = 500.00f;	// for demonstation only!
		virtual void doSomething(float);
		virtual ~Account(){ 	// ~ is the destructor, nothing radical here!
		}
};

void Account::doSomething(float amount){
	cout << "This method in the account class." << endl;
	cout << "Incoming Balance. " << balance << endl; 
	balance = balance + amount;
	cout << "Outgoing Balance. " << balance << endl;
}

class Current: public Account{
	
	public:
	float newBalance = 500.00f;
	virtual void doSomethingElse(float);
};

void Current::doSomethingElse(float anotherAmount){
	cout << "This method in the current class." << endl;
	cout << "Incoming Balance. " << newBalance << endl; 
	newBalance = newBalance - anotherAmount;
	cout << "Outgoing Balance. " << balance << endl;
}

class Test{
	public:
		float x, y;
};

// demo function
void someFunction(int& c){
	c++; // c can be modified
	cout << "c has value " << c << endl;	//will output 11
}

int main(){

	float f = 200.6f;	// f at end indicates single precision, which requires less memory (default is double). 
		// narrowing conversion, but we have notified the compiler
	int x = static_cast<int>(f);
	cout << "Converted f = " << f << " to x = " << x << endl;
	
	/* The new operator denotes a request for memory allocation on the Free Store. 
	If sufficient memory is available, a new operator initializes the memory
	and returns the address of the newly allocated 
	and initialized memory to the pointer variable.
	*/
	
	Account myTest;
	myTest.doSomething(200.00);
	
	Current myTest2;
	myTest2.doSomethingElse(100.00);
	cout << "Test of inheritance." << endl;
	myTest2.doSomething(300.00);
	
	Account *a = new Current; //upcast - cast derived to base
	a->doSomething(400.00);	
	//type-safe downcast - cast base to derived
	Current *c = dynamic_cast<Current*>(a);
	
	const int i = 10;	// Note i is a constant
	//someFunction(i);	// is an error because someFunction
						// could modify the value of i
	someFunction(*const_cast<int*>(&i));
		// Allow i to be passed to the function but it will remain at 10.
	cout << "i has value " << i << endl; // will still output 10
	
	a = new Account;
	a->balance = 1000;
		//convert account address to long
	long addr = reinterpret_cast<long>(a);
	
	// safe to convert long address into an account
	Account* b = reinterpret_cast<Account*>(addr);
	cout << "The balance of b is " << b->balance <<endl;
	
	// safe to convert to any class regardless of
	// inheritance - ok this time! (not safe)
	Current* cur = reinterpret_cast<Current*>(addr);
	cout << "The balance of cur is " << cur->balance << endl;
	
	// works, but definitely not safe this time!}
	Test* test = reinterpret_cast<Test*>(addr);
	cout << "The value of the float x is " << test->x <<
		" and float y is " << test->y << endl;
}