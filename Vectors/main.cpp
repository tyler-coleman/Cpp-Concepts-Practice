//
//  main.cpp
//  Vectors
//
//  Created by Tyler Coleman on 2/23/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<string> strings; // Optional to declare initial size of vector.
    
    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");
    
    cout << strings.size() << endl;
    
    for (int i = 0; i < strings.size(); i++) {
        cout << strings[i] << endl; // [] operator overloaded to access vector elements like an array
    }
    
    vector<string>::iterator it = strings.begin();
    
    cout << *it << endl; // iterator object overloads * to dereference element of vector it points to
                         // Can increment it with ++
    
    // Better syntax
    for (vector<string>::iterator it = strings.begin(); it != strings.end(); it++) {
        cout << *it << endl;
    }
    
    return 0;
}
