//
//  common.h
//  LeetCode
//
//  Created by Rajarshi Biswas on 2/13/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#ifndef common_h
#define common_h

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <deque>
#include <list>
#include <pair>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif /* common_h */
