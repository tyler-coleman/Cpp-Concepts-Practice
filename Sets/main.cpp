//
//  main.cpp
//  Sets
//
//  Created by Tyler Coleman on 2/24/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//
// Set only stores unique elements, and orders them as well.

#include <iostream>
#include <set>

using namespace std;


class Test {
private:
    int id;
    string name;
    
public:
    Test() : id(0), name("") {}
    Test(int id, string name) : id(id), name(name) {}
    
    Test(const Test &other) {
        name = other.name;
        id = other.id;
    }
    
    void print() const {
        cout << id << ": " << name << endl;
    }
    
    bool operator<(const Test &other) const {
        return name < other.name;
    }
};

int main(int argc, const char * argv[]) {
    
    set<int> numbers;
    
    numbers.insert(10);
    numbers.insert(30);
    numbers.insert(30);
    numbers.insert(20);
    numbers.insert(50);
    
    for (set<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }
    
    set<int>::iterator it_find = numbers.find(30);
    
    if (it_find != numbers.end()) {
        cout << "Found: " << *it_find << endl;
    }
    
    // For a set, count returns only either 0 or 1. 0 = false, 1 = true.
    if (numbers.count(30)) {
        cout << "Number found!" << endl;
    }
    
    set<Test> tests;
    
    tests.insert(Test(10,"Mike"));
    tests.insert(Test(30,"Joe"));
    // Insert won't happen because < overload only compares name and sees an entry already
    // exists in the set with name "Joe."
    tests.insert(Test(333,"Joe"));
    tests.insert(Test(20,"Su"));
    
    for (set<Test>::iterator it = tests.begin(); it != tests.end(); it++) {
        it->print();
    }
    
    return 0;
}
