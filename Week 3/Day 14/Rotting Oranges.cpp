int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> time(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        
        for(int i = 0; i < grid.size(); ++ i){
            for(int j = 0; j < grid[0].size(); ++ j){
                if(grid[i][j] == 2){
                    bfs(grid, time, i, j);
                }
            }
        }
        for(int i = 0; i < grid.size(); ++ i){
            for(int j = 0; j < grid[0].size(); ++ j){
                if(grid[i][j] == 1 && time[i][j] == INT_MAX){
                    return -1;
                }
                if(grid[i][j] == 1){
                    ans = max(ans, time[i][j]); // when regarding the whole matrix, we get the max value.
                }
            }
        }
        return ans;
    }