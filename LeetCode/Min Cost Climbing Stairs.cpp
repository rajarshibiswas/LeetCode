//
//  Min Cost Climbing Stairs.cpp
//  LeetCode https://leetcode.com/problems/min-cost-climbing-stairs/description/
//
//  Created by Rajarshi Biswas on 2/14/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//
/*
 On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
 Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
 
 Example 1:
 Input: cost = [10, 15, 20]
 Output: 15
 Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
 Example 2:
 Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
 Output: 6
 Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
 Note:
 cost will have a length in the range [2, 1000].
 Every cost[i] will be an integer in the range [0, 999].
 */


#include <stdio.h>
#include "common.h"
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //unsigned int minCost = 0;
        vector<unsigned int> dpTable(cost.size()+1, INT_MAX);
        // No Cost for not going anywhere.
        dpTable [0] = 0;
        dpTable [1] = cost[0];
        
        for (int i = 1; i < cost.size(); i++) {
            dpTable[i+1] = cost[i] + min(dpTable[i], dpTable[i-1]);
        }
        return min(dpTable[cost.size()], dpTable[cost.size() - 1]);
    }
};














