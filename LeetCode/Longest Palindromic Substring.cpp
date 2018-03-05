//
//  Longest Palindromic Substring.cpp
//  LeetCode
//
//  Created by Rajarshi Biswas on 3/4/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        vector <vector<bool>> table (length, vector<bool> (length, false));
        //bool table[length][length];
        int max_len = 1;
        int start_index = 0;
        
        
        for (int i = 0; i < length; i++) {
            table[i][i] = true;
        }
        
        for (int i = 0; i < length - 1; i++) {
            if (s[i] == s[i+1]) {
                table[i][i+1] = true;
                max_len = 2;
                start_index = i;
            }
        }
        
        for (int len = 3;  len <= length; len++) {
            for (int i = 0; i <= length - len; i++) {
                int end = i + len - 1;
                
                if (s[i] == s[end] && table[i+1][end-1]) {
                    table[i][end] = true;
                    if (len > max_len) {
                        // cout << i << "--"<< end << endl;
                        max_len = len;
                        start_index = i;
                    }
                }
            }
        }
        //  cout << start_index << "--" << max_len;
        return s.substr(start_index, max_len);
        
    }
};
