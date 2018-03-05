//
//  Find All Anagrams in a String.cpp
//  LeetCode: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
//
//  Created by Rajarshi Biswas on 3/4/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> sv (26,0);
        vector <int> pv (26,0);
        vector <int> result;
        
        if (p.length() > s.length())
            return result;
        
        for (int i = 0; i < p.length(); i++) {
            pv[p[i]-'a'] += 1;
            sv[s[i]-'a'] += 1;
        }
        
        if (sv == pv) {
            result.push_back(0);
        }
        
        for (int i = p.length(); i < s.length(); i++) {
            sv[s[i-p.length()] - 'a'] -= 1;
            sv[s[i] - 'a'] += 1;
            if(sv == pv)
                result.push_back(i-p.length()+1);
        }
        return result;
    }
};

