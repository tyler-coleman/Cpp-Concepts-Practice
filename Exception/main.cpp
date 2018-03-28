//
//  main.cpp
//  Exception
//
//  Created by Tyler Coleman on 2/20/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//
#include <iostream>

using namespace std;


void mightGoWrong() {
    
    bool error1 = false;
    bool error2 = true;
    
    if (error1) {
        throw "Something went wrong";
    }
    
    if (error2) {
        throw string("Something else went wrong");
    }
}

void usesMightGoWrong() {
    mightGoWrong();
}

int main(int argc, const char * argv[]) {
    
    try {
        usesMightGoWrong();
    } catch (int e) {
        cout << "Error code: " << e << endl;
    } catch (char const *e) {
        cout << "Error message: " << e << endl;
    } catch (string &e) {
        cout << "Error message: " << e << endl;
    }
    
    cout << "Still running" << endl;
    
    
    return 0;
}
