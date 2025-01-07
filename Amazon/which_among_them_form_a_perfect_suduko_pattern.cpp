class Solution {
public:
    bool is_possible(vector<vector<char>>&board,int row_index, int column_index,char curr_num){

        // single loop to check all the elements in a particular row and column
        for(int i =0;i<9;i++){
            if(board[i][column_index] == curr_num || board[row_index][i] == curr_num)
                return false;
        }
        // grid wise check;
        int row = (row_index/3)*3;
        // cout<<"row in a grid "<<row<<endl;

        int col = (column_index/3)*3;
        // cout<<"col in a grid "<<col<<endl;

        for(int i = row ; i<row + 3;i++){
            for(int j = col; j<col+3;j++){
                if(board[i][j] == curr_num)return false;
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i =0;i<9;i++){
            for(int j =0;j<9;j++){
                if(board[i][j] != '.'){
                    char curr_num = board[i][j];
                    board[i][j] = '.';
                    if(!is_possible(board,i,j,curr_num))return false;
                }
            }
        }
        return true;
        
    }
};