//
//  Construct Binary Tree from String.cpp
//  LeetCode: https://leetcode.com/problems/construct-binary-tree-from-string/
//
//  Created by Rajarshi Biswas on 2/18/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

class Solution {
public:
    TreeNode* str2tree(string s) {
        stack <TreeNode *> myS;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(') {
                continue;
            }
            if (isdigit(ch) || ch == '-') {
                int value = 0;
                int sig = 1;
                if (ch == '-') {
                    sig = -1;
                    i++;
                }
                while (i < s.size() && isdigit(s[i])) {
                    value = value * 10 + s[i++] - '0';
                }
                myS.push(new TreeNode(value*sig));
                i--;
            } else {
                TreeNode *c = myS.top(); myS.pop();
                TreeNode *p = myS.top();
                !p->left ? p->left = c: p->right = c;
            }
        }
        
        return myS.empty() ? nullptr : myS.top();
    }
};
