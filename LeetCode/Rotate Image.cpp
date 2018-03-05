//
//  Rotate Image.cpp
//  LeetCode
//
//  Created by Rajarshi Biswas on 3/4/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix[0].size();
        if (n == 0) {
            return;
        }
        
        for (int layer = 0; layer < n/2; layer++) {
            int first = layer;
            int last = n - layer - 1;
            //cout << first << "," << last << "\n";
            for (int i = first; i < last; i++) {
                int offset = i - first;
                int top = matrix[first][i];
                //cout << top << ",";
                matrix[first][i] = matrix[last - offset][first];
                matrix[last - offset][first] = matrix[last][last-offset];
                matrix[last][last-offset] = matrix[i][last];
                matrix[i][last] = top;
                
            }
            
        }
    }
};
