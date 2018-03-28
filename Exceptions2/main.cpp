//
//  main.cpp
//  Exceptions2
//
//  Created by Tyler Coleman on 2/20/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <iostream>

using namespace std;

class CanGoWrong {
    
public:
    CanGoWrong() {
        char *pMemory = new char[99999999999999999];
        delete [] pMemory;
    }
};



int main(int argc, const char * argv[]) {
    
    try {
        CanGoWrong wrong;
    } catch (bad_alloc &e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    
    cout << "Still running." << endl;
    
    return 0;
}
