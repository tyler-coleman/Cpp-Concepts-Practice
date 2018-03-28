//
//  main.cpp
//  Stacks and Queues
//
//  Created by Tyler Coleman on 2/24/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Test {
private:
    string name;
    
public:
    Test() : name("") {}
    Test(string name) : name(name) {}
    ~Test() {
        //cout << "Object destroyed!" << endl;
    }
    
    void print() const {
        cout << name << endl;
    }
};

int main(int argc, const char * argv[]) {

    // LIFO
    stack<Test> test_stack;
    
    test_stack.push(Test("Mike"));
    test_stack.push(Test("John"));
    test_stack.push(Test("Su"));
    
    // No way to iterate through a stack or queue.
    // If you need to iterate through a stack or queue, you need a different data structure.
    
    Test test1 = test_stack.top();
    test1.print();
    
    test_stack.pop();
    
    // STL implementations usually return a reference to an object.
    // Using = below invokes a shallow copy provided by C++ to construct test2.
    // Can define our own copy constructor to avoid copying instance variables
    // such as pointers.
    Test test2 = test_stack.top();
    test2.print();
    
    // Object is destroyed upon invoking pop()
    test_stack.pop();
    
    // Can declare instance as a reference.
    Test &test3 = test_stack.top();
    test_stack.pop();
    // This is invalid code.
    // Since we are declaring test3 as a reference to test with name "Mike," and then
    // destroying said test, we are left with a reference to an unknown area of memory.
    // Might work by coincidence.
    test3.print();
    
    // Getting a copy of popped object is less efficient, but ensures you have an instance
    // to work with after popping the object.
    
    cout << endl;
    
    test_stack.push(Test("Mike"));
    test_stack.push(Test("John"));
    test_stack.push(Test("Su"));
    
    // Only way to iterate through stack is to remove elements.
    while (test_stack.size() > 0) {
        Test &test = test_stack.top();
        test.print();
        test_stack.pop();
    }
    
    cout << endl;
    
    // FIFO
    queue<Test> test_queue;
    
    test_queue.push(Test("Mike"));
    test_queue.push(Test("John"));
    test_queue.push(Test("Su"));
    
    test_queue.back().print();
    
    cout << endl;
    
    while (test_queue.size() > 0) {
        Test &test = test_queue.front();
        test.print();
        test_queue.pop();
    }
    
    return 0;
}
