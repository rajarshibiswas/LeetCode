//
//  Monotone Increasing Digits.cpp
//  LeetCode : https://leetcode.com/problems/monotone-increasing-digits/
//
//  Created by Rajarshi Biswas on 2/19/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "common.h"

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string n = to_string(N);
        int marker = n.length();
        for (int i = n.length() - 1; i >= 1; i--) {
            if (n[i-1] > n [i]) {
                marker = i;
                n[i-1] = n[i-1]-1;
            }
                
        }
        for (int i = marker; i < n.length(); i++) {
            n[i] = '9';
        }
        return stoi(n);
    }
};
