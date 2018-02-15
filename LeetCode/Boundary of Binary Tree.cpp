//
//  Boundary of Binary Tree.cpp
//  LeetCode https://leetcode.com/problems/boundary-of-binary-tree/description/
//
//  Created by Rajarshi Biswas on 2/15/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool isLeaf(TreeNode *root) {
        if (root != NULL && root->left == NULL &&
            root->right == NULL) {
            return true;
        } else {
            return false;
        }
    }
    
    void addLeaf(TreeNode *root, vector<int>& result) {
        if (root == NULL)
            return;
        if (isLeaf(root)) {
            result.push_back(root->val);
        }
        addLeaf(root->left, result);
        addLeaf(root->right, result);
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        if (!isLeaf(root)) {
            result.push_back(root->val);
        }
        // Add the left boundary.
        TreeNode *t = root->left;
        while (t != NULL) {
            if (!isLeaf(t)){
                result.push_back(t->val);
            }
            if (t->left) {
                t = t->left;
            } else {
                t = t->right;
            }
        }
        
        // Add the leaf nodes
        addLeaf(root, result);
        
        // Add the right boundary
        stack<int> myS;
        t = root->right;
        while (t != NULL) {
            if (!isLeaf(t)) {
                myS.push(t->val);
            }
            if (t->right != NULL) {
                t = t->right;
            } else {
                t = t->left;
            }
        }
        while (!myS.empty()) {
            result.push_back(myS.top()); myS.pop();
        }
        
        return result;
        
    }
};












