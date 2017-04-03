class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.size() == 0) return 0;
        int row = M.size();
        int count = 0;
        
        for(int i = 0; i < row; i++){
            for(int j = i; j < row; j++){
                if(M[i][j] == 1){
                    dfs(M,i,j,row);
                    count++;
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<int>>& M,int i, int j, int row){
        M[i][j] = 0;
        for(int k = 0; k < row; k++){
            if(M[k][j] == 1)
                dfs(M,k,j,row);
        }
        for(int k = 0; k < row; k++){
            if(M[i][k] == 1)
                dfs(M,i,k,row);
        }
    }
};
