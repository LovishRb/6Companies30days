class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();

        queue<pair<int,int>> q;
        int count_of_ones = 0;
        int minutes =-1;
        for(int row =0;row<rows;row++){
            for(int col =0;col<columns;col++){
                if(grid[row][col] == 1){
                    count_of_ones++;
                }
                if(grid[row][col] == 2){
                    q.push({row,col});
                }

            }
        }

        if(count_of_ones == 0)return 0;

        if(q.empty())return -1;

        // travers queue;
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                
                auto [x,y] = q.front();
                q.pop();

                for(auto [dir_x,dir_y] : directions){
                    int row = x + dir_x;
                    int col = y + dir_y;

                    if(row>=0 && row<rows && col >= 0 && col<columns && grid[row][col]==1 ){
                        grid[row][col] = 2;
                        q.push({row,col});
                        count_of_ones--;
                    }
                }

                
            }

            minutes++;
        }

        if(count_of_ones == 0) return minutes;

        return -1;
    }
};