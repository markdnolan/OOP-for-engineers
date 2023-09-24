//
//  main.cpp
//  Casts
//
//  Created by domain_management on 9/24/23.
//
//  Demonstrates the use of casting to change type of variiables.

// Start reading from main() function to help make it easier to understand

#include<iostream>

using namespace std;

// Demo classes with a virtual base class

class Account{
    public:
        float balance = 500.00f;    // for demonstation only!
        virtual void doSomething(float);
        virtual ~Account(){     // ~ is the destructor, nothing radical here!
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
    //float newBalance = 500.00f;
    virtual void doSomethingElse(float);
};

void Current::doSomethingElse(float anotherAmount){
    cout << "This method in the current class." << endl;
    cout << "Incoming Balance. " << balance << endl;
    balance = balance - anotherAmount;
    cout << "Outgoing Balance. " << balance << endl;
}

class Test{ public: float x, y;};

// demo function
void someFunction(int& c){
    c++; // c can be modified
    cout << "c has value " << c << endl;    //will output 11
}

int main(){

    float f = 200.6f;    // f at end indicates single precision, which requires less memory (default is double).
        // narrowing conversion, but we have notified the compiler
    int x = static_cast<int>(f);
    cout << "Converted f = " << f << " to x = " << x << endl;
    
    //  This has converted the floating point variable f to an integer x, this is safe since a floartting point number can ALWAYS be shortened to an integer (with loss of precision).
    
    Account myTest;
    myTest.doSomething(200.00);
    // Object "myTest" is of type "Account".
    
    Current myTest2;
    myTest2.doSomethingElse(100.00);
    cout << "Test of inheritance." << endl;
    myTest2.doSomething(300.00);
    // Object "myTest2" is of type "Current".
    
    Account *a = new Current; //upcast - cast derived to base
    a->doSomething(400.00);
    
    // a is a pointer of type "Account" pointing to a new object of type "Current".
    // This is safe because tyep "Account" understands all the methods defined in "Current".
    // HOWEVER using a to call a method in "Current" not defined in "Account" will cause a compile error (see below).
    
    // a->doSomethingElse(45.45);   // ERROR:No member named 'doSomethingElse' in 'Account'
    
    
    cout << endl << "DYNAMIC CAST." << endl << endl;
    //type-safe downcast - cast base to derived
    a->doSomething(0);
    Current *c = dynamic_cast<Current*>(a);
    if (c) {
        c->doSomething(100.0);
        c->doSomethingElse(200.00);
    }
    a->doSomething(0.0);
    /* c is a pointer of type "Current". a is a pointer of type "Account".
     Using the dynamic cast operator make pointer c a copy of pointer a but with type "Current" (they still point to the same object of yype "Current".
     Notice that "c" has the same balance as "a", but "c" can now call "doSomethingElse" method.
     Also, NOTE, check for existence of "c" , this checks at runtime that dynamic cast was successful (if fails, "c" will be NULL).
     Also, notice that the same "balance" variable is updated by both "a" and "c".
    */
    
    cout << endl << "CONSTANT CAST" << endl << endl;
    
    const int i = 10;    // Note i is a constant
    //someFunction(i);    // is an error because someFunction
                        // could modify the value of i
    someFunction(*const_cast<int*>(&i));
        // Allow i to be passed to the function but it will remain at 10.
    cout << "i has value " << i << endl; // will still output 10
    
    cout << endl << "REINTERPRET CAST" << endl << endl;
    
    a = new Account;
    // "a" is a pointer to an instance of class "Account", it has type "Account".
    a->balance = 1000.0;
    a->doSomething(0.0);
    
    //make "addr" a copy of pointer "a" but with type "long".
    long addr = reinterpret_cast<long>(a);
    cout << "The value of a is: " << a << endl;
    cout << "The value of addr is: " << addr << endl;
    
    // Safe to convert "addr" of type "long" back into a type "Account" becuause we know it was a pointer to type "Account" before!
    //
    Account* b = reinterpret_cast<Account*>(addr);
    cout << "The value of b is: " << b << endl;
    
    cout << "The balance of b is " << b->balance <<endl;
    
    // safe to convert to any class regardless of
    // inheritance - ok this time! (not safe)
    Current* cur = reinterpret_cast<Current*>(addr);
    cout << "The balance of cur is " << cur->balance << endl;
    
    // works, but definitely not safe this time!, x & y could be anything!
    Test* test = reinterpret_cast<Test*>(addr);
    cout << "The value of test is: " << test << endl;
    cout << "The value of the float x is " << test->x <<
        " and float y is " << test->y << endl;
}
