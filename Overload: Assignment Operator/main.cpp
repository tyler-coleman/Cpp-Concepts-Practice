//
//  main.cpp
//  Overload: Assignment Operator
//
//  Created by Tyler Coleman on 2/24/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//
// C++ rule of 3:
// If any of a copy constructor, a destructor, or an assignment operator overload
// are implemented, the other two should also be implemented.

#include <iostream>

using namespace std;

class Test {
private:
    int id;
    string name;
    
public:
    Test() : id(0), name("") {}
    Test(int id, string name) : id(id), name(name) {}
    
    Test(const Test &other) {
        id = other.id;
        name = other.name;
        
        // Can also write:
        // *this = other;
        // to take advantage of already-overloaded assignment operator.
        
        cout << "Copy constructor running!" << endl;
    }
    
    void print() const {
        cout << id << ": " << name << endl;
    }
    
    // Return type of equals operator is a reference to type of object
    // being worked on.
    const Test &operator=(const Test &other) {
        
        id = other.id;
        name = other.name;
        
        cout << "Assignment running!" << endl;
        
        return *this;
    }
};

int main(int argc, const char * argv[]) {
    
    Test test1(10,"Mike");
    test1.print();
    
    Test test2(20,"Bob");
    
    // C++ provides default implementation in the form of a shallow copy.
    // Doesn't work if, for example, instances contain a unique ID.
    // How can we override default = behavior?
    test2 = test1;
    test2.print();
    
    Test test3;
    
    // Equivalent to test3 = test2;
    test3.operator=(test2);
    
    cout << endl;
    
    // Copy initialization (will not invoke overloaded =).
    // If you create an object and don't initialize it, but immediately assign another object
    // to it, copy constructor is used, not = operator.
    Test test4 = test1;
    test4.print();
    
    return 0;
}
