class Solution {
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m < 3) return;
        int n = board[0].size();
        if(n < 3) return;
        
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O')
                solveHelper(board,0,j,m,n);
            if(board[m - 1][j] == 'O')
                solveHelper(board,m-1,j,m,n);
        }
        
        for(int i = 0;  i < m; i++){
            if(board[i][0] == 'O')
                solveHelper(board,i,0,m,n);
            if(board[i][n - 1] == 'O')
                solveHelper(board,i,n-1,m,n);
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'C')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
        return;
    }
    
    void solveHelper(vector<vector<char>>& board,int i, int j,int m, int n){
        board[i][j] = 'C';
        for(int k = 0; k < 4; k++){
            int i_dir = i + dir[k][0];
            int j_dir = j + dir[k][1];
            if(i_dir >= 0 && i_dir <= m - 1 && j_dir >= 0 && j_dir <= n - 1 && board[i_dir][j_dir] == 'O')
                solveHelper(board,i_dir,j_dir,m,n);
        }
        return;
    }
};