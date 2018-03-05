//
//  Best Time to Buy and Sell StocK.cpp
//  LeetCode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
//
//  Created by Rajarshi Biswas on 3/4/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int price : prices) {
            minPrice = min(price, minPrice);
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};
