//
//  main.cpp
//  2DVector
//
//  Created by Tyler Coleman on 2/24/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector< vector<int> > grid(3,vector<int>(4,0)); // Declare a 3 row, 4 column vector initialized to contain zeroes.
    
    grid[1].push_back(8);
    
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[row].size(); col++) {
            
            cout << grid[row][col] << flush;
        }
        
        cout << endl;
    }
    
    
    return 0;
}
