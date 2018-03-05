//
//  Valid Parentheses.cpp
//  LeetCode: https://leetcode.com/problems/valid-parentheses/description/
//
//  Created by Rajarshi Biswas on 3/4/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

class Solution {
public:
    bool isValid(string s) {
        
        stack <char> my_stack;
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            if (ch == '(' || ch == '{' || ch == '[') {
                my_stack.push(ch);
            } else {
                if(my_stack.empty()) {
                    return false;
                }
                switch (ch) {
                    case ')':
                        if (my_stack.top() != '(') {
                            return false;
                        } else {
                            //cout << "popping";
                            my_stack.pop();
                        }
                        break;
                    case '}':
                        if (my_stack.top() != '{') {
                            return false;
                        } else {
                            my_stack.pop();
                        }
                        break;
                    case ']':
                        if (my_stack.top() != '[') {
                            return false;
                        } else {
                            my_stack.pop();
                        }
                        break;
                }
            }
        }
        
        if (!my_stack.empty()) {
            return false;
        } else {
            return true;
        }
        
    }
};
