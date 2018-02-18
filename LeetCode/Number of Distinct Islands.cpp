//
//  Number of Distinct Islands.cpp
//  LeetCode : https://leetcode.com/problems/number-of-distinct-islands/
//
//  Created by Rajarshi Biswas on 2/18/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//

#include <stdio.h>
#include "common.h"

class Solution {
private:
    bool dfs(int r, int c, int r0, int c0, vector<vector<int>> &grid,
             vector<vector<int>> &shape) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() ||
            grid[r][c] == 0) {
            return false;
        }
        shape.push_back({r-r0,c-c0});
        grid[r][c] = 0;
        dfs(r+1, c, r0, c0, grid, shape);
        dfs(r, c+1, r0, c0, grid, shape);
        dfs(r-1, c, r0, c0, grid, shape);
        dfs(r, c-1, r0, c0, grid, shape);
        return true;
        
    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        set <vector<vector<int>>> islands;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                vector<vector<int>> shape;
                if (dfs(i, j, i, j, grid, shape) == true) {
                    islands.insert(shape);
                }
            }
        }
        return islands.size();
    }
};
