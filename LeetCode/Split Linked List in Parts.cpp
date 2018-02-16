//
//  Split Linked List in Parts.cpp
//  LeetCode: https://leetcode.com/problems/split-linked-list-in-parts/description/
//
//  Created by Rajarshi Biswas on 2/15/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector <ListNode*> result(k, nullptr);
        int len = 0;
        ListNode *temp = root;
        while(temp) {
            len++;
            temp = temp->next;
        }
        int max_node = len/k; // Maximum splits in one pair.
        int dist_node = len % k; // Needs to distribute this equally
        temp = root;
        ListNode *prev = NULL;
        for (int i = 0; temp && i < k; i++, dist_node--) {
            // Till the splits end or node empty
            result[i] = temp;
            for (int j = 0; j < max_node + ((dist_node > 0) ? 1 : 0);
                 j++) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL; // just put an end for that string.
            
        }
        return result;
        
    }
};
