//
//  main.cpp
//  Map with Custom Key
//
//  Created by Tyler Coleman on 2/24/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

class Person {
    
private:
    
    string name;
    int age;
    
public:
    
    Person() : name(""), age(0) {}
    Person(string name, int age) : name(name), age(age) {}
    
    // Default copy constructor given by C++ only does a shallow copy of state variables.
    // Not good if a member variable is a pointer and the new instance should not have the
    // same pointer. Define your own copy constructor.
    Person (const Person &other) {
        name = other.name;
        age = other.age;
    }
    
    // Declared as const as method is not allowed to change instance variables.
    // Important because map keys are returned as const.
    void print() const {
        cout << name << ": " << age << flush;
    }
    
    // In order to use custom objects as keys in a map, need to overload < operator
    // to enable map to sort by key. Need both const in in order to work. Method should
    // not alter this or other.
    bool operator<(const Person &other) const {
        // return name < other.name; <----- this is wrong
        if (name == other.name) {
            return age < other.age;
        } else {
            return name < other.name;
        }
    }
};


int main(int argc, const char * argv[]) {
    
    map<Person, int> people;
    
    people[Person("Mike", 40)] = 40;
    // Because overloaded < operator doesn't consider age of key, map interprets both "Mike" keys
    // as identical. Does not update key in map, but still considers them equal and updates value.
    // Updated < overload to consider matching names with different ages.
    people[Person("Mike", 25)] = 25;
    people[Person("Sue", 30)] = 30;
    people[Person("Raj", 20)] = 20;
    
    for (map<Person, int>::iterator it = people.begin(); it != people.end(); it++) {
        cout << it->second << ": " << flush;
        it->first.print();
        cout << endl;
    }
    
    return 0;
}
