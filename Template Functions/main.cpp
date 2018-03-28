//
//  main.cpp
//  Template Functions
//
//  Created by Tyler Coleman on 2/28/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <iostream>

using namespace std;

template<class T>
void print(T n) {
    cout << "Template version: " << n << endl;
}

template<class T>
void show() {
    cout << T() << endl;
}

void print(int value) {
    cout << "Non-template version: " << value << endl;
}

int main(int argc, const char * argv[]) {
    
    print<string>("Hello");
    print<int>(5);
    
    // Don't actually need to specify type. C++ infers type from arguments.
    print("Hi there");
    
    // Unless function is overloaded and a non-template version takes the argument
    // type and the argument type isn't specified using the template syntax.
    print(6);
    print<>(6);
    
    // show(); won't work because C++ cannot infer type and call constructor inside
    // of template function
    
    // Will output whatever the default constructor for double returns.
    show<double>();
    
    return 0;
}


