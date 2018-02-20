//
//  Insert Delete GetRandom.cpp
//  LeetCode : https://leetcode.com/problems/insert-delete-getrandom-o1/
//
//  Created by Rajarshi Biswas on 2/20/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

class RandomizedSet {
private:
    vector <int> nums;
    unordered_map<int, size_t> keyMap; // Map of value to vector index.
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (keyMap.find(val) != keyMap.end()) {
            return false;
        }
        nums.push_back(val); // Insert the value in the vector
        keyMap[val] = nums.size()-1; // insert the value and vector pos in the map
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (keyMap.find(val) == keyMap.end()) {
            return false;
        }
        int last_elemnet = nums.back();
        keyMap[last_elemnet] = keyMap[val]; // Swap the index in the map;
        nums[keyMap[last_elemnet]] = last_elemnet; // Copy the last element value.
        keyMap.erase(val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return (nums[rand() % nums.size()]);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
