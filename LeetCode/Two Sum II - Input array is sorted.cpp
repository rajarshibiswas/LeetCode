//
//  Two Sum II - Input array is sorted.cpp
//  LeetCode: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
//
//  Created by Rajarshi Biswas on 3/10/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector <int> result(2);
        
        while (l < r) {
            if ((numbers[l]+numbers[r]) == target) {
                result[0] = l+1;
                result[1] = r+1;
                break;
            }
            if ((numbers[l]+numbers[r]) > target){
                r--;
            } else {
                l++;
            }
            
        }
        return result;
    }
};
