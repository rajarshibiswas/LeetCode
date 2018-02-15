//
//  Serialize and Deserialize BST.cpp
//  LeetCode
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
};

class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "#";
        return (to_string(root->val) + "," + serialize(root->left) +
                "," + serialize(root->right));
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return helper(data);
    }
    
    TreeNode* helper(string &data) {
        if (data[0] == '#') {
            if (data.size() > 1) {
                data = data.substr(2);
            }
            return NULL;
        }
        TreeNode *root = new TreeNode(val(data));
        root->left = helper(data);
        root->right = helper(data);
        return root;
    }
    
    int val (string &data) {
        int value = 0;
        size_t pos = data.find(',');
        string s = data.substr(0, pos);
        data = data.substr(pos+1);
        value = stoi(s);
        return value;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
