/*
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

Example 1:

Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 
Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.
*/

class Solution {
public:
    bool pass(vector<vector<int>>& grid,vector<pair<int,int>> indexes)
    {
        int m = grid.size();
        int n = grid[0].size();
        bool changed = false;
        for(auto it : indexes)
        {
            int i = it.first;
            int j = it.second;
            
            if(i-1>=0 && grid[i-1][j]==1)
            {
                grid[i-1][j] = 2;
                changed = true;
            }
            if(i+1 <m && grid[i+1][j]==1)
            {
                grid[i+1][j] = 2;
                changed = true;
            }
            if(j-1>=0 && grid[i][j-1]==1)
            {
                grid[i][j-1] = 2;
                changed = true;
            }
            if(j+1<n && grid[i][j+1]==1)
            {
                grid[i][j+1] = 2;
                changed = true;
            }
        }
        return changed;
    }
    int orangesRotting(vector<vector<int>>& grid) {
       
        int m = grid.size();
        int n = grid[0].size();
        int min = 0;
        while(true)
        {
            bool changed = false;
            vector<pair<int,int>>indexes;
            for(int i =0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j]==2)
                    {
                        indexes.push_back({i,j});
                    }
                }
            }
            if(indexes.size())
            {
                changed = pass(grid,indexes);
                if(changed)
                 min++;
                else
                    break;
            }
            else
                break;
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    min = -1;
                    break;
                }
            }
        return min;
    }
};
