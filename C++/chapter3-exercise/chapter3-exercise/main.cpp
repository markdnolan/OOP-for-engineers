//
//  main.cpp
//  chapter3-exercise
//
//  Created by domain_management on 9/30/23.
//

#include <iostream>
#include <string>

using namespace std;

class Person {
    
private:
    string name;
    string address;
    string telephone;
    
public:
    
    Person(string, string, string);
    
    virtual void display();
    virtual void setAddress(string);
    virtual void setTelephone(string);
    
};

Person::Person(string namePassed, string addressPassed, string telephonePassed):
    name(namePassed), address(addressPassed), telephone(telephonePassed) {
    }

void Person::display() {
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Telephone: " << telephone << endl;
}

void Person::setAddress(string newAddress) {
    cout << "Setting new address." << endl;
    address = newAddress;
    Person::display();
}

void Person::setTelephone(string newTelephone) {
    cout << "Setting new telephone number." << endl;
    telephone = newTelephone;
    Person::display();
}

class Staff: public Person {
    
private:
    string office;
    string staffID;
    double salary;
    
public:
    
    Staff(Person, string, string, double);
    
    void display();
    void setOffice(string);
    void addPayRise(double);
};

Staff::Staff(Person personPassed, string officePassed, string staffIDPassed, double salaryPassed):
    Person(personPassed), office(officePassed), staffID(staffIDPassed), salary(salaryPassed) {
        cout << "Creating staff member" << endl;
        Staff::display();
}

void Staff::display() {
    Person::display();
    cout << "Office: " << office << endl;
    cout << "Staff ID: " << staffID << endl;
    cout << "Salary: $" << salary << endl;
}

void Staff::setOffice(string newOffice) {
    cout << "Setting new office." << endl;
    office = newOffice;
    Staff::display();
}

void Staff::addPayRise(double percentIncrease) {
    cout << endl << "Old salary: $" << salary << endl;
    cout << "Increasing by " << percentIncrease << "%" << endl;
    salary += (salary * (percentIncrease / 100));
    cout << "New salary: $" << salary << endl << endl;;
}

int main() {
    
    Person mark("Mark Nolan", "7 Times Square", "555-846-6543");
    mark.display();
    
    Staff markStaff(mark, "G234", "ID456", 100000);
    
    markStaff.addPayRise(5);
    
    markStaff.display();
    
    return 0;
}
