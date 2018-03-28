//
//  main.cpp
//  Complex STL Data Types
//
//  Created by Tyler Coleman on 2/24/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//
// Can use nested STL types to represent any conceivable data structure.

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    
    // Declare a map connecting people with their test scores.
    map<string, vector<int> > scores;
    
    scores["Mike"].push_back(10);
    scores["Mike"].push_back(20);
    scores["Vicki"].push_back(15);
    
    for (map<string, vector<int> >::iterator it = scores.begin(); it != scores.end(); it++) {
        string name = it->first;
        vector<int> score_list = it->second;
        
        cout << name << ": " << flush;
        
        for (int i = 0; i < score_list.size(); i++) {
            cout << score_list[i] << " " << flush;
        }
        
        cout << endl;
    }
    
    return 0;
}
