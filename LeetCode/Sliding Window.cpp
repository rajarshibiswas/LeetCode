//
//  Sliding Window.cpp
//  LeetCode: https://leetcode.com/problems/sliding-window-maximum/
//
//  Created by Rajarshi Biswas on 2/20/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//
// k = 3
// size = 6
// 0 1 2 3 4 5
// i     k
#include <stdio.h>
#include "common.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector <int> result;
        deque<int> dq; // Double ended queue to store the max value index in a window
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front(); // remove the last element from the last window
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
                // Remove all the small elements.
            }
            // Push the new element.
            dq.push_back(i);
            // start putting value in the result after one window
            if (i >= k-1 ) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
        
    }
};
