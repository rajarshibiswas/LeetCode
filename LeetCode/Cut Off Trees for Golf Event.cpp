//
//  Cut Off Trees for Golf Event.cpp
//  LeetCode: https://leetcode.com/problems/cut-off-trees-for-golf-event/description/
//
//  Created by Rajarshi Biswas on 2/20/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

class Solution {
private:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0 , 1, 0, -1};
    
public:
    int bfs(vector<vector<int>>& forest, int sr, int sc, int tr, int tc) {
        // r, c, cost;
        int cost = 0;
        queue <pair<pair<int,int>, int>> myQ;
        vector<vector<bool>> visited (forest.size(),vector<bool>(forest[0].size(), false));
        myQ.push({{sr, sc}, cost});
        visited[sr][sc] = true;
        //cout << "\n=------= \n";
        while (!myQ.empty()) {
            auto val = myQ.front(); myQ.pop();
            int cost = val.second;
            //cout << val.first.first << "," << val.first.second << endl;
            if (val.first.first == tr && val.first.second == tc) {
                return cost;
            }
            for (int i = 0; i < 4; i++) {
                int r = dr[i] + val.first.first;
                int c = dc[i] + val.first.second;
                //cout << "\n entering - "<< r  <<"," << c << endl;
                if (r >= 0 && r < forest.size() && c >= 0 && c < forest[0].size()
                    && visited[r][c] == false && forest[r][c] != 0) {
                    visited[r][c] = true;
                    myQ.push({{r,c},cost+1});
                }
            }
            
        }
        //cout << "WTF" << endl;
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        int result = 0;
        size_t r = forest.size();
        size_t c = forest[0].size();
        vector <pair<pair<int,int>,int>> tree;
        if (r == 0 && c == 0) return -1;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (forest[i][j] > 1) {
                    tree.push_back({{i,j}, forest[i][j]});
                }
            }
        }
        // Sort the tree heights
        sort(tree.begin(), tree.end(), [](const pair<pair<int,int>,int> &a,
                                          const pair<pair<int,int>,int> &b) -> bool {
            return a.second < b.second;
        });
        
        // Starting 0,0 try to reach all the tree positions using bfs
        int sr = 0, sc = 0;
        for (auto a: tree) {
            int path = bfs(forest, sr, sc, a.first.first, a.first.second);
            if (path == -1) {
                return -1;
            }
            result = result+path;
            sr = a.first.first;
            sc = a.first.second;
        }
        return result;
    }
};
