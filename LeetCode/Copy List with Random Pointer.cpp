//
//  Copy List with Random Pointer.cpp
//  LeetCode: https://leetcode.com/problems/copy-list-with-random-pointer/description/
//
//  Created by Rajarshi Biswas on 3/4/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *temp = head;
        while (temp != NULL) {
            RandomListNode *t1 = new RandomListNode(temp->label);
            t1->next = temp->next;
            temp->next = t1;
            temp = t1->next;
        }
        temp = head;
        while (temp != NULL) {
            if (temp->random) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        
        temp = head;
        RandomListNode *dummy = new RandomListNode(0);
        RandomListNode *runner = dummy;
        
        while (temp != NULL) {
            runner->next = temp->next;
            runner = runner->next;
            
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};
