//
//  Image Smoother.cpp
//  LeetCode https://leetcode.com/problems/image-smoother/solution/
//
//  Created by Rajarshi Biswas on 2/14/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector <vector<int>> result (M.size(), vector <int> (M[0].size()));
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M[0].size(); j++) {
                int count = 0;
                int sum = 0;
                for (int r = i - 1; r  <= i + 1; r++) {
                    for (int c = j - 1 ; c <= j + 1; c++) {
                        if (r >= 0 && r < M.size() &&
                            c >= 0 && c < M[0].size()) {
                            count++;
                            sum += M[r][c];
                        }
                    }
                }
                result[i][j] = sum / count;
            }
        }
        return result;
    }
};
