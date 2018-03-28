//
//  main.cpp
//  License Key Formatting
//
//  Created by Tyler Coleman on 3/1/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <iostream>
#include <list>
#include <cassert>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        
        int k = 0;
        list<char> formatted;
        
        
        for (auto it = S.rbegin(); it != S.rend(); it++) {
            // Ignore dashes while reverse iterating.
            if (*it == '-') continue;
            
            formatted.push_front(*it);
            if (++k % K == 0) {
                formatted.push_front('-');
            }
        }
        
        if (formatted.front() == '-') {
            L:?????????????????
