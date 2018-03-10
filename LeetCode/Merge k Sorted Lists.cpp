//
//  Merge k Sorted Lists.cpp
//  LeetCode: https://leetcode.com/problems/merge-k-sorted-lists/discuss/10527/Difference-between-Priority-Queue-and-Heap-and-C++-implementation
//
//  Created by Rajarshi Biswas on 3/10/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    struct compare {
        bool operator() (const ListNode *l1, const ListNode* l2) {
            return l1->val > l2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        for(auto l : lists) {
            if (l != NULL) {
                q.push(l);
            }
        }
        if (q.empty()) return NULL;
        ListNode *result = q.top(); q.pop();
        if (result->next) {
            q.push(result->next);
        }
        ListNode *tail = result;
        
        while (!q.empty()) {
            tail->next = q.top(); q.pop();
            tail = tail->next;
            if (tail->next)
                q.push(tail->next);
        }
        return result;
    }
};
