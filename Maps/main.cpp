//
//  main.cpp
//  Maps
//
//  Created by Tyler Coleman on 2/24/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <iostream>


int main(int argc, const char * argv[]) {
    
    map<string, int> ages; // Declares a map with string-type key and value-type int.
    
    ages["Mike"] = 40;
    ages["Raj"] = 20;
    ages["Vicki"] = 30;
    
    ages["Mike"] = 70; // Overwrites original value at key.
    
    pair<string, int> add_to_map("Peter", 100);
    ages.insert(add_to_map);
    ages.insert(pair<string, int>("Bob", 35)); // Same thing.
    ages.insert(make_pair("Susan", 45)); // Same thing.
    
    cout << ages["Sue"] << endl;
    // Accessing a nonexistant key with overloaded [] automatically adds a new element to map.
    // Use a check to determine if map contains a key.
    
    if (ages.find("Vicki") != ages.end()) {
        cout << "Found Vicki." << endl;
    } else {
        cout << "Key not found." << endl;
    }
    
    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        // it->first accesses key, it->second accesses value.
        cout << it->first << ": " << it->second << endl;
    }
    
    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        // Accomplishes the same thing.
        pair<string, int> age = *it;
        cout << age.first << ": " << age.second << endl;
    }
    
    
    return 0;
}
