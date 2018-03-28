//
//  main.cpp
//  Abstract Classes
//
//  Created by Tyler Coleman on 2/28/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//
// Abstract classes for a hierarchy of classes where the base class
// doesn't make any sense to instantiate.

#include <iostream>

using namespace std;

// Abstract class contains methods without implementation.
// "Pure virtual methods"
class Animal {
public:
    virtual void speak() = 0; // = 0 notation denotes a pure virtual function.
    virtual void run() = 0;
};

// Must provide implementations for all virtual functions of Animal, otherwise
// Dog is still abstract.
class Dog: public Animal {
public:
    // virtual keyword not necessary, but helps with clarity.
    virtual void speak() {
        cout << "woof" << endl;
    }
};

class Labrador: public Dog {
public:
    Labrador() {
        cout << "new labrador" << endl;
    }
    
    virtual void run() {
        cout << "Labrador running" << endl;
    }
};

void test(Animal &a) {
    a.run();
}

int main(int argc, const char * argv[]) {
    
    Labrador lab;
    lab.speak();
    lab.run();
    
    Labrador labs[5];
    
    Animal *animals[5];
    
    // Can add any object of subclass of Animal that implements the virtual functions
    // to array.
    
    animals[3] = &lab;
    animals[3]->speak();
    
    test(*animals[3]);
    test(lab);
    
    return 0;
}
