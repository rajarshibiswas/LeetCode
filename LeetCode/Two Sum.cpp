//
//  Two Sum.cpp
//  LeetCode: https://leetcode.com/problems/two-sum/
//
//  Created by Rajarshi Biswas on 3/4/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> result;
        
        unordered_map <int, int> my_map;
        
        for (int i = 0; i < nums.size(); i++) {
            if (my_map.find(target - nums[i]) != my_map.end()) {
                result.push_back(i);
                result.push_back(my_map[target-nums[i]]);
                return result;
            }
            my_map[nums[i]] = i;
        }
        return result;
    }
};
