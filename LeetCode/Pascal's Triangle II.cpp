//
//  Pascal's Triangle II.cpp
//  LeetCode
//
//  Created by Rajarshi Biswas on 2/19/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector <int> result (rowIndex+1);
        result[0] = 1;
        
        for (int i = 1; i <= rowIndex; i++) {
            for(int j=i; j>=1; j--) {
                result[j] = result[j] + result[j-1];
            }
        }
        return result;
    }
};
