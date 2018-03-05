//
//  LRU Cache.cpp
//  LeetCode: https://leetcode.com/problems/lru-cache/description/
//
//  Created by Rajarshi Biswas on 3/4/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        cache_t::iterator ct = cache.find(key);
        if (ct == cache.end()) {
            return -1;
        }
        
        touch(ct);
        return ct->second.first;
    }
    
    void put(int key, int value) {
        cache_t::iterator ct = cache.find(key);
        if (ct != cache.end()) {
            touch(ct);
        } else {
            if (cache.size() == capacity) {
                cache.erase(lru.back());
                lru.pop_back();
            }
            lru.push_front(key);
        }
        cache[key] = {value, lru.begin()};
    }
    
private:
    typedef list<int> L_t;
    typedef pair<int, L_t::iterator> P_t;
    typedef unordered_map<int, P_t> cache_t;
    
    void touch(cache_t::iterator it) {
        int key = it->first;
        
        lru.erase(it->second.second);
        lru.push_front(key);
        it->second.second = lru.begin();
        
    }
    
    cache_t cache;
    L_t lru;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
