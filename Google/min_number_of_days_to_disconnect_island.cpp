class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == 0 || visited[row][col]) 
            return;
        

        
        visited[row][col] = true;

        // direction to move in all 4 directions and explore whther the island exist or not

        dfs(grid, row + 1, col, visited); 
        dfs(grid, row - 1, col, visited); 
        dfs(grid, row, col + 1, visited); 
        dfs(grid, row, col - 1, visited); 
    }
    int no_of_island(vector<vector<int>>& grid){
        int count=0;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i =0;i<grid.size();++i){
            for(int j =0;j<grid[0].size();++j){
                if(!visited[i][j] && grid[i][j] == 1){
                    // move to islands
                    dfs(grid,i,j,visited);
                    count++;
                }

            }

        }
        return count;
    }
    int minDays(vector<vector<int>>& grid) {
        
        int count = no_of_island(grid);
        // cout<<no_of_island(grid)<<endl;
        if(count > 1)return 0;
        if(count == 0)return 0;

        for(int i =0;i<grid.size();++i){
            for(int j =0;j<grid[0].size();++j){
                if(grid[i][j] == 0)continue;

                grid[i][j] = 0;
                if(no_of_island(grid) != 1)return 1;

                grid[i][j] = 1;

            }

        }
        return 2;
    }
};