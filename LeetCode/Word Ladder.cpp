//
//  Word Ladder.cpp
//  LeetCode: https://leetcode.com/problems/word-ladder/description/
//
//  Created by Rajarshi Biswas on 2/11/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//  Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
/*  Only one letter can be changed at a time.
 Each transformed word must exist in the word list. Note that beginWord is not a transformed
 word.
 For example,
 Given:
 beginWord = "hit"
 endWord = "cog"
 wordList = ["hot","dot","dog","lot","log","cog"]
 As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 return its length 5.
 */

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> list;
        queue<string> visited;
        for (auto word : wordList) {
            list.insert(word);
        }
        //list.insert(endWord);
        int depth = 2;
        findNextWord(beginWord, list, visited);
        
        while (!visited.empty()) {
            size_t size = visited.size();
            while (size--) {
                string cur = visited.front(); visited.pop();
                if (cur == endWord) {
                    return depth;
                }
                findNextWord(cur, list, visited);
            }
            depth++;
        }
        return 0;
    }
    
    // Find the next word while doing BFS
    void findNextWord(string word, unordered_set<string> &list,
                      queue<string> &visited) {
        list.erase(word);
        for (int i = 0; i < word.size(); i++) {
            char letter = word[i];
            for (int k = 0; k < 26; k++) {
                word[i] = 'a' + k;
                if (list.find(word) != list.end()) {
                    // The word is prsent in the dict
                    visited.push(word);
                    list.erase(word);
                }
            }
            word[i] = letter;
        }
    }
};













