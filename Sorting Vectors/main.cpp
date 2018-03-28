//
//  main.cpp
//  Sorting Vectors
//
//  Created by Tyler Coleman on 2/24/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//
// Deque is a queue that you can add to the front of, not as efficient as a vector but you know it's
// probably useful sometimes.

#include <iostream>
#include <vector>

using namespace std;

class Test {
private:
    int id;
    string name;
public:
    Test() : id(0), name("") {}
    Test(int id, string name) : id(id), name(name) {}
    
    void print() const {
        cout << id << ": " << name << endl;
    }
    
    bool operator<(const Test &other) const {
        if (name == other.name) {
            return id < other.id;
        } else {
            return name < other.name;
        }
    }
    
    // Function prototype with friend keyword allows function to access private variables.
    friend bool comp(const Test &a, const Test &b);
};

bool comp(const Test &a, const Test &b) {
    return a.name < b.name;
}

int main(int argc, const char * argv[]) {
    
    vector<Test> tests;
    
    tests.push_back(Test(5,"Mike"));
    tests.push_back(Test(10,"Su"));
    tests.push_back(Test(7,"Raj"));
    tests.push_back(Test(3,"Vicki"));
    
    // Need to implement < operator in class to sort vector. Except not necessarily.
    // sort(tests.begin(),tests.end());
    
    // Can also write a comparison function and pass its pointer to sort.
    sort(tests.begin(),tests.end(),comp);
    
    for (int i = 0 ; i < tests.size(); i++) {
        tests[i].print();
    }
    
    // Vectors are a good option if they are sorted only occasionally.
    // If our data needs to be maintained sorted elsehow at all times, should look
    // into other data structures.
    
    return 0;
}
