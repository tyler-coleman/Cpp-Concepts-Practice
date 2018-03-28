//
//  main.cpp
//  Vectors and Memory
//
//  Created by Tyler Coleman on 2/23/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<double> numbers;
    
    unsigned long capacity = numbers.capacity(); // Returns size of internal array.
    cout << "Capacity: " << capacity << endl;

    for (int i = 0; i < 10000; i++) {
        
        if (numbers.capacity() != capacity) {
            capacity = numbers.capacity();
            cout << "Capacity: " << capacity << endl;
        }
        
        numbers.push_back(i);
    }
    
    // Clearing reduces size to 0 but does not reduce capacity.
    numbers.clear();
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;
    
    numbers.resize(100); // Changes internal variable "size" of vector
    numbers.reserve(50000); // Increases capacity
    
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;
    
    return 0;
}
