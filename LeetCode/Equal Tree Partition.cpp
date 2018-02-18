//
//  Equal Tree Partition.cpp
//  LeetCode: https://leetcode.com/problems/equal-tree-partition/description/
//
//  Created by Rajarshi Biswas on 2/15/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//
#include <stdio.h>
#include "common.h"

class Solution {
private:
    int helper(TreeNode *root, stack<int>& myS) {
        if (root == NULL) {
            return 0;
        }
        myS.push(helper(root->left, myS)+ root->val+helper(root->right, myS));
        return myS.top();
    }
    
public:
    bool checkEqualTree(TreeNode* root) {
        stack<int> myS;
        int sum = helper(root, myS);
        myS.pop(); // Dont need to check the total element.
        if (sum % 2 == 0) {
            while(!myS.empty()) {
                int s = myS.top(); myS.pop();
                if (s == sum/2) {
                    return true;
                }
            }
        }
        return false;
    }
};
