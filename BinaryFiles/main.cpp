//
//  main.cpp
//  StructPadding
//
//  Created by Tyler Coleman on 2/23/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

#pragma pack(push, 1) // Aligns following data on single-byte boundaries.

struct Person {
    // Cannot use string as it allocates space in stack as a pointer to data in heap.
    char name[50];
    int age;
    double height;
    
    // Adding a single char c to struct does not increase size of struct from 64. Why??
    // C++ automatically performs some padding of struct to help it run more efficiently.
    // If we want to store data to binary file, need to disable this padding --> #pragma pack()
};

#pragma pack(pop) // Restores default padding.

int main(int argc, const char * argv[]) {
    
    cout << sizeof(Person) << endl;
    
    Person someone = {"Frodo", 220, 0.8};
    
    string file_name = "test.bin";
    
    // Write binary file
    
    ofstream outf;
    outf.open(file_name, ios::binary); // Need to pass ios::binary, default file type is text.
                                       // If using more generic fstream instead of ofstream, must
                                       // pass argument ios::binary|ios::out.
    
    if (outf.is_open()) {
        
        outf.write((char *)&someone, sizeof(Person)); // Can also use reinterpret_cast<char*>(&someone) to cast to char *
        outf.close();
    } else {
        cout << "Could not create file: " << file_name << endl;
    }
    
    // Read binary file
    
    ifstream inf;
    inf.open(file_name, ios::binary);
    
    Person someone_else = {};
    
    if (inf.is_open()) {
        
        inf.read((char *)&someone_else, sizeof(Person)); // Can also use reinterpret_cast<char*>(&someone) to cast to char *
        inf.close();
    } else {
        cout << "Could not read file: " << file_name << endl;
    }

    cout << someone_else.name << ", " << someone_else.age << ", " << someone_else.height << endl;
    
    return 0;
}
