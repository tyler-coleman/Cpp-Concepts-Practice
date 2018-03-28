//
//  main.cpp
//  Maps with Custom Value
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
        cout << "Copy constructor running." << endl;
        name = other.name;
        age = other.age;
    }
    
    void print() const {
        cout << name << ": " << age << endl;
    }
};

int main(int argc, const char * argv[]) {
    
    map<int, Person> people;
    
    people[0] = Person("Mike", 40);
    people[1] = Person("Alan", 25);
    people[2] = Person("Susan", 35);
    
    people.insert(make_pair(50, Person("Bob", 42)));
    
    for (map<int, Person>::iterator it = people.begin(); it != people.end(); it++) {
        cout << it->first << ": " << flush;
        it->second.print();
    }
    
    return 0;
}
