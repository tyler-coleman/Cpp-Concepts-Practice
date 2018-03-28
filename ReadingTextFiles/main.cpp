//
//  main.cpp
//  ReadingTextFiles
//
//  Created by Tyler Coleman on 2/20/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    // See writing text files for alternate stream declaration/use.
    
    ifstream inf;
    string input_file_name = "test.txt";
    
    inf.open(input_file_name);
    
    if (inf.is_open()) {
        
        string line;
        
        
        // Can also use while(inf)
        // ! operator is overloaded in fstream class
        while (!inf.eof()) {
            getline(inf,line);
            cout << line << endl;
        }
        
        inf.close();
    } else {
        cout << "Cannot open file: " << input_file_name << endl;
    }
    
    return 0;
}
