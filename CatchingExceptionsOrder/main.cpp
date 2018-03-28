//
//  main.cpp
//  CatchingExceptionsOrder
//
//  Created by Tyler Coleman on 2/20/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <iostream>
#include <exception>

using namespace std;

// Using std exception as parent class and bad_alloc as child class

void goesWrong() {
    
    bool error1_detected = true;
    bool error2_detected = false;
    
    if (error1_detected) {
        throw bad_alloc();
    }
    
    if (error2_detected) {
        throw exception();
    }
}

int main(int argc, const char * argv[]) {
    
    // Will catch exception object before bad_alloc object because bad_alloc is a subclass of exception.
    // Must be careful to catch subclasses before parent classes in exception handling.
    try {
        goesWrong();
    } catch (exception &e) {
        cout << e.what() << endl;
    } catch (bad_alloc &e) {
        cout << e.what() << endl;
    }
    
    return 0;
}
