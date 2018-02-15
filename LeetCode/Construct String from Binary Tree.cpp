//
//  Construct String from Binary Tree.cpp
//  LeetCode https://leetcode.com/problems/construct-string-from-binary-tree/description/
//
//  Created by Rajarshi Biswas on 2/14/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"


typedef struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
private:
    string helper(TreeNode *t) {

        string result = "";
        if (t == NULL)
            return result;
        
        result = to_string(t->val);
        
        if (t->left) {
            result = result + "(" + helper(t->left) + ")";
        } else if (t->right) {
            result = result + "()";
        }
        if (t->right) {
            result = result + "(" + helper(t->right) + ")";
        }
        return result;
    }
    
    
public:
    string tree2str(TreeNode* t) {
        return helper(t);
    }
};
