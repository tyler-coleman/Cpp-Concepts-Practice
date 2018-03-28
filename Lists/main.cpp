//
//  main.cpp
//  Lists
//
//  Created by Tyler Coleman on 2/24/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;

int main(int argc, const char * argv[]) {
    
    list<int> numbers;
    
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(0);
    
    list<int>::iterator it = numbers.begin();
    it++;
    numbers.insert(it, 100); // Inserts 100 before element pointed to by iterator. Iterator remains pointed
                             // to the 1 it pointed to before.
    
    cout << "Element: " << *it << endl;
    
    list<int>::iterator erase_it = numbers.begin();
    erase_it++;
    erase_it = numbers.erase(erase_it);
    
    cout << "Element: " << *erase_it << endl; // After erasing, iterator may point to repurposed memory.
                                              // erase() method returns iterator to next element.
    
    for (list<int>::iterator it = numbers.begin(); it != numbers.end();) {
        if (*it == 2) {
            numbers.insert(it, 1234);
        }
        
        if (*it == 1) {
            it = numbers.erase(it); // In effect increments the iterator.
        } else {
            it++;                   // Only want to force iterator to increment if an element is not deleted.
        }                           // More elegantly implemented with a while loop.
    }
    
    for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }
    
    return 0;
}
