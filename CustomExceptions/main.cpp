//
//  main.cpp
//  CustomExceptions
//
//  Created by Tyler Coleman on 2/20/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <iostream>
#include <exception>

using namespace std;

class MyException: public exception {
public:
    virtual const char* what() const throw() {
        return "Something bad happened.";
    }
};

class Test {
public:
    void goesWrong() {
        throw MyException();
    }
};


int main(int argc, const char * argv[]) {
    
    Test test;
    
    try {
        test.goesWrong();
    } catch (MyException &e) {
        cout << e.what() << endl;
    }
    
    return 0;
}
