//
//  main.cpp
//  Function Pointers
//
//  Created by Tyler Coleman on 2/28/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test() {
    cout << "Hello" << endl;
}

void test2(int value) {
    cout << value << endl;
}

bool match(string test) {
    return (test.size() == 3);
}

// Takes a vector of strings and a pointer to a function to test individual strings.
int countStrings(vector<string> texts, bool (*match)(string test)) {
    
    int count = 0;
    
    for (vector<string>::iterator it = texts.begin(); it != texts.end(); it++) {
        if (match(*it)) count++;
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    
    test();
    
    void (*pTest)();
    // Can also initialize using
    // void (*pTest)() = test;
    
    pTest = test;
    // pTest = &test also works, but it's also redundant.
    // Function name is a pointer to function.
    
    (*pTest)();
    // Don't actually need to dereference *pTest, because () implies
    // the function pointer to be dereferenced.
    
    pTest();
    
    void (*pTest2)(int) =  test2;
    test2(3);
    
    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("four");
    texts.push_back("five");
    texts.push_back("six");
    texts.push_back("seven");
    texts.push_back("eight");
    
    cout << match("one") << endl;
    
    // count_if is included with <algorithm>
    cout << count_if(texts.begin(), texts.end(), match) << endl;
    
    // Using our own defined function.
    cout << countStrings(texts, match) << endl;
    
    return 0;
}
