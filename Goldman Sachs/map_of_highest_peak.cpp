class Solution {
private:
    bool is_valid_pos(pair<int,int> neighbour,int rows,int cols){
        return neighbour.first >=0 && neighbour.second >= 0 && neighbour.first < rows && neighbour.second < cols;
    }
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int cols = isWater[0].size();
        int dx[4] ={0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        vector<vector<int>> ans(rows,vector<int>(cols,-1));

        queue<pair<int,int>> q;
        for(int row =0;row<rows;row++){
            for(int col = 0;col<cols;col++){
                if(isWater[row][col] == 1){
                    ans[row][col] = 0;
                    q.push({row,col});
                }
            }
        }
        int layer = 1 ;
        while(!q.empty()){
            int size = q.size();

            for(int i =0;i<size ; i++){
                pair<int,int> curr = q.front();
                q.pop();

                for(int d = 0 ; d<4;d++){
                    pair<int,int> neighbour = {curr.first + dx[d] , curr.second + dy[d]};

                    if(is_valid_pos(neighbour,rows,cols) && ans[neighbour.first][neighbour.second] == -1){
                        q.push(neighbour);
                        ans[neighbour.first][neighbour.second] = layer;
                    }
                }

            }

            layer++;
        }
        return ans;

    }
};