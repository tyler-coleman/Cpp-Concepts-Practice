//
//  main.cpp
//  Overload: Insertion Operator for Printing
//
//  Created by Tyler Coleman on 2/24/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

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
        *this = other;
    }
    
    void print() const {
        cout << id << ": " << name << endl;
    }
    
    const Test &operator=(const Test &other) {
        
        id = other.id;
        name = other.name;
        
        return *this;
    }
    
    // Declared as friend so that it can access private variables of &test.
    // Only need to declare friend in .h file, not in implementation.
    // friend is here only because we are implementing in the same space as we are declaring.
    friend ostream &operator<<(ostream &out, const Test &test) {
        out << test.id << ": " << test.name;
        return out;
    }
};


int main(int argc, const char * argv[]) {
    
    Test test1(10,"Mike");
    Test test2(20,"Joe");
    test1.print();
    
    // Let's overload << to be able to avoid calling print function.
    // Bit-shift operator has left-right associativity.
    // (cout << test1) returns a reference to an object of type ostream.
    // Because first type of << operator is not of type Test, cannot implement as a method
    // of Test (Test is not the implicit argument type).
    // Will have to implement a friend function.
    cout << test1 << endl << test2 << endl;
    
    return 0;
}
