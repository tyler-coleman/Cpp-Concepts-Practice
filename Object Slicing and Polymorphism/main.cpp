//
//  main.cpp
//  Object Slicing and Polymorphism
//
//  Created by Tyler Coleman on 2/28/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <iostream>

using namespace std;

class Parent {
private:
    int one;
public:
    // When a copy constructor is defined, we lose implicit default constructor.
    // We must define a default constructor of Parent if it has any child classes.
    // Otherwise, we must specify the constructor of Parent used when instantiating
    // an object of class Child.
    Parent(const Parent &other) : one(0) {
        
        one = other.one;
        
        // !!!
        // Cannot initialize two in the case of constructing a Parent reference to
        // a child object.
        // Parent class cannot know what private variables/constructors belong to
        // its children.
        cout << "Copy Parent" << endl;
    }
    
    Parent() : one(0) {
        cout << "Default Parent" << endl;
    }
    
    // virtual allows you to declare a reference of type Parent pointed to an object
    // of type Child and call any virtual functions of Parent as implemented by Child.
    virtual void print() {
        cout << "parent" << endl;
    }
};

class Child: public Parent {
private:
    int two;
public:
    // Cannot initialize one in Child class.
    // one is limited to scope of class Parent.
    // However, Child() does automatically call Parent() constructor.
    Child() : two(0) {}
    
    void print() {
        cout << "child" << endl;
    }
};

int main(int argc, const char * argv[]) {
    
    Child c1;
    // This is known as object slicing, where we essentially are throwing away data
    // belonging to the Child class that doesn't exist in the Parent class.
    // See !!! above.
    Parent &p1 = c1;
    
    // Without virtual keyword above, p1.print() will call Parent's implementation of
    // print(), because p1 is a reference to a Parent.
    // With virtual keyword, C++ instead calls Child's implementation.
    p1.print();
    
    Parent p2 = Child();
    
    
    return 0;
}
