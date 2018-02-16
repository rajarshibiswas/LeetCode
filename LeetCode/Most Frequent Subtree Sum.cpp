//
//  Most Frequent Subtree Sum.cpp
//  LeetCode: https://leetcode.com/problems/most-frequent-subtree-sum/description/
//
//  Created by Rajarshi Biswas on 2/15/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector <int> result;
        unordered_map<int, int> counts;
        int maxCount = 0;
        
        postOrder(root, counts, maxCount);
        for (auto it : counts) {
            if (it.second == maxCount) {
                result.push_back(it.first);
            }
        }
        return result;
    }
    
    int postOrder(TreeNode *root, unordered_map<int, int> &counts,
                  int &maxCount) {
        if (root == NULL)
            return 0;
        int sum = root->val;
        sum += postOrder(root->left, counts, maxCount);
        sum += postOrder(root->right, counts, maxCount);
        ++counts[sum];
        maxCount = max(maxCount, counts[sum]);
        return sum;
        
    }
};
