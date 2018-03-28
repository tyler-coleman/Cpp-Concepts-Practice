//
//  main.cpp
//  Complex Number Class
//
//  Created by Tyler Coleman on 2/24/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//
// C++ has a standard complex number class, however we will build one
// here to get a better idea of operator overloading.

#include <iostream>
#include "Complex.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Complex c1(2,3);
    
    Complex c2 = c1;
    Complex c3;
    
    c3 = c1;
    
    cout << c1 << endl;
    
    Complex c4(3,4);
    
    cout << c1 + c4 << endl;
    
    cout << c1 + 4 << endl;
    cout << 6 + c3 << endl;
    
    if (c1 == c2 + 3) {
        cout << "Complex numbers are equivalent." << endl;
    } else {
        cout << "Complex numbers are not equivalent." << endl;
    }
    
    if (c1 != c2) {
        cout << "Nice stuff." << endl;
    }
    
    cout << c1 << endl << *c1 << endl;
    
    return 0;
}
