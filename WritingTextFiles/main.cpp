//
//  main.cpp
//  WritingTextFiles
//
//  Created by Tyler Coleman on 2/20/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    ofstream outf;
    // fstream outf;    <---- ALTERNATE
    
    string output_file_name = "text.txt";
    
    outf.open(output_file_name);
    // outf.open(out_file_name, ios::out); <---- ALTERNATE
    
    if (outf.is_open()) {
        outf << "Hello there." << endl;
        outf << 123 << endl;
        outf.close();
    } else {
        cout << "Could not create file: " << output_file_name << endl;
    }
    
    return 0;
}
