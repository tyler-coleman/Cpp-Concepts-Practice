//
//  main.cpp
//  Multimaps
//
//  Created by Tyler Coleman on 2/24/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//
// Needed occasionally, but more often than not a simpler solution is availabe.

#include <iostream>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    
    multimap<int, string> lookup;
    
    // multimap doesn't include overloaded [] operator
    lookup.insert(make_pair(30, "Mike"));
    lookup.insert(make_pair(10, "Vicki"));
    // multimap allows for duplicate keys.
    lookup.insert(make_pair(20, "Raj"));
    lookup.insert(make_pair(20, "Bob"));
    
    for (multimap<int, string>::iterator it = lookup.begin(); it != lookup.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
    
    // Not useful, returns iterator to first matched key found and continues iterating to
    // end of map.
    for (multimap<int, string>::iterator it = lookup.find(10); it != lookup.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
    
    cout << endl;
   
    // Returns a pair of iterators to start and end of range matching specified key.
    pair< multimap<int, string>::iterator, multimap<int, string>::iterator > its = lookup.equal_range(20);
    
    for (multimap<int, string>::iterator it = its.first; it != its.second; it++) {
        cout << it->first << ": " << it->second << endl;
    }
    
    cout << endl;
    
    // In C++11, use keyword auto to determine type for you.
    auto its2 = lookup.equal_range(20);
    
    for (auto it = its2.first; it != its2.second; it++) {
        cout << it->first << ": " << it->second << endl;
    }
    
    return 0;
}
