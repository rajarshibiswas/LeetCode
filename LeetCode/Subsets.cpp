//
//  Subsets.cpp
//  LeetCode: https://leetcode.com/problems/subsets/description/
//
//  Created by Rajarshi Biswas on 3/10/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector<int>> result;
        helper(result, {}, nums, 0);
        return result;
    }
    
    void helper(vector<vector<int>> &result, vector<int> path,
                vector<int>& nums, int index) {
        result.push_back(path);
        
        for (int i = index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            helper(result, path, nums, i+1);
            path.pop_back();
        }
    }
    
};

