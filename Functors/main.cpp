//
//  main.cpp
//  Functors
//
//  Created by Tyler Coleman on 3/3/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//
// This shit makes no sense.

#include <iostream>

using namespace std;

struct Test {
    virtual bool operator()(string &text)=0;
};

// This is a functor.
// A class or struct that, among other things, overloads the () operator.
struct MatchTest: public Test {
    virtual bool operator()(string &text) {
        return text == "lion";
    }
};

void check(string text, Test &test) {
    if(test(text)) {
        cout << "Text matches!" << endl;
    } else {
        cout << "No match!" << endl;
    }
}

int main(int argc, const char * argv[]) {

    MatchTest pred;
    
    string value = "lion";
    
    // Looks like a function call, but really it's just the overloaded () operator.
    cout << pred(value) << endl;
    
    MatchTest m;
    
    check("lion", m);
    
    return 0;
}
