//
//  main.cpp
//  Chapter3-separate-compiliation
//
//  Created by domain_management on 9/30/23.
//

#include "Account.hpp"

int main() {
        
    Account a = Account("Mark Nolan", 35.00, 123457);
    Account b(a);
    
    a.display();
    b.display();    // Copy constructor increments account number & resets balance to $0.00.
    
    a.makeDeposit(100.0);
    
    a.display();    // Account a now has a balance of $135.00.
    b.display();    // Account b still has the initial balance of $0.00.
    
    return 0;
}
