//
//  Partition Labels.cpp
//  LeetCode: https://leetcode.com/problems/partition-labels/
//
//  Created by Rajarshi Biswas on 3/4/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector <int> last_offset(26,-1);
        
        // Store the last seen offset of each char
        for (int i = 0; i < s.length(); i++) {
            last_offset[s[i]-'a'] = i;
        }
        
        int j = 0;
        int anchor = 0;
        vector <int> ans;
        
        for (int i = 0; i < s.length(); i++) {
            j = max (j, last_offset[s[i]-'a']);
            if (i == j) {
                ans.push_back(i - anchor + 1);
                anchor = i+1;
            }
        }
        return ans;
    }
};
