//
//  Binary Tree Right Side View.cpp
//  LeetCode: https://leetcode.com/problems/binary-tree-right-side-view/description/
//
//  Created by Rajarshi Biswas on 3/10/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void helper(TreeNode *root, vector<int>& result, int lev) {
        if (root == NULL)
            return;
        if (lev >= result.size()) {
            result.push_back(root->val);
        }
        helper(root->right, result, lev+1);
        helper(root->left, result, lev+1);
        return;
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        helper(root, result, 0);
        return result;
    }
};
