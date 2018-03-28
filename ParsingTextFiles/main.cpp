//
//  main.cpp
//  ParsingTextFiles
//
//  Created by Tyler Coleman on 2/20/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    fstream input;
    
    string file_name = "stats.txt";
    input.open(file_name);
    
    if (!input.is_open()) {
        // error code
        return 1;
    }
    
    while (input) {
        string line;
        
        // Delimiter is ':'
        getline(input, line, ':');
        
        int population;
        input >> population;
        
        // Discard end line character at end of line.
        // input.get();
        // With C++ 11, can read input into ws (whitespace) to discard all extra whitespace after line.
        // More robust.
        input >> ws;
        
        if (!input)
            break;
        
        cout << line << " -- "  << population << endl;
    }
    
    input.close();
    
    return 0;
}
