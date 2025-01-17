class Solution {
public:
    bool check(vector<vector<char>>& board, int i, int j) {
        if (i > 0 && board[i - 1][j] == 'X') return false; 
        if (j > 0 && board[i][j - 1] == 'X') return false; 
        return true;
    }

    int countBattleships(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        int cnt =0;

        for(int i =0;i<row;i++){
            for(int j =0;j<col;j++){
                if (board[i][j] == 'X' && check(board, i, j)) cnt++;
            
            }
        }
        return cnt;
    }
};