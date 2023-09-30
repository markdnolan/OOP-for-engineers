//
//  main.cpp
//  cpp-pointers
//
//  Created by domain_management on 9/24/23.
//
// Pointer example

#include<iostream>

using namespace std;

int main(){
    int x[5] = {1,2,3,4,5,};
    int *q, *p= &x[0];                    // create 2 pointers q & p, set p to point to the address of the first value in the array i.e. x[0]
    // Increment all values in an array by 1
    q = p;                                                // set q to p i.e. address of x[0]
    for (int i=0; i<5; i++){                            // for first pass i=0, for last pass i=4
        cout << "Before increment, i = " << i << endl;
        cout << "Before increment, *q = " << *q << endl;    // *q = value pointed to by q
        cout << "Before increment, q = " << q << endl;
        (*q++)++;                                            // value pointed to by q is incremented (the increment outside the brackets which acts on the brackets)
                                                            // THEN address pointed to by q is incremented
        cout << "After increment, i = " << i << endl;
        cout << "After increment, *q = " << *q << endl;
        cout << "After increment, q = " << q << endl;
    }

    // reset q pointer back to p i.e. address of x[0]
    cout << "second loop" << endl;
    q = p;
    for (int i=0; i<5; i++){
        cout << "Before increment, *q = " << *q << endl;    // *q = value pointed to by q
        cout << "Before increment, q = " << q << endl;
        (*(q+i))++;                                            // this time q+i is resolved first then value pointed to by *(q+i) is incremented
        cout << "After increment, *q = " << *q << endl;
        cout << "After increment, q = " << q << endl;
    }
        
    // do I need to reset q this time? no!
        
    for (int i=0; i<5; i++){
            cout << "x[" << i << "] = " << x[i] <<
                " at address " << &x[i] <<
                    " and the value of p is " << *(p+i) <<
                        " at address " << p+i << endl;
    }
}

