class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result = 0;
        int m = grid.size();
            if(m == 0) return result;
        int n = grid[0].size();
            if(n == 0) return result;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    if(i == 0 || grid[i - 1][j] == 0)
                        result++;
                    if(i == m - 1 || grid[i + 1][j] == 0)
                        result++;
                    if(j == 0 || grid[i][j - 1] == 0)
                        result++;
                    if(j == n - 1 || grid[i][j + 1] == 0)
                        result++;
                }
            }
        }
        return result;
    }
};
