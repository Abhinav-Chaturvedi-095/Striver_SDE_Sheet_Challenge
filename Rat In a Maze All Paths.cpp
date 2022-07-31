void allPaths(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &curr, vector<vector<int>> &ans) {
    if(i == maze.size() - 1 && j == maze.size() - 1) {
        vector<int> temp;
        for(int i = 0; i < maze.size(); i++) {
            for(int j = 0; j < maze.size(); j++) {
                temp.push_back(curr[i][j]);
            }
        }
        temp[temp.size() - 1] = 1;
        ans.push_back(temp);
        return;
    }
    if(i < maze.size() - 1 && curr[i + 1][j] != 1 && maze[i + 1][j] == 1) {
            curr[i][j] = 1;
            allPaths(i + 1, j, maze, curr, ans);
            curr[i][j] = 0;
        }
    
    if(j > 0 && curr[i][j - 1] != 1 && maze[i][j - 1] == 1) {
            curr[i][j] = 1;
            allPaths(i, j - 1, maze, curr, ans);
            curr[i][j] = 0;
        }
    
    if(j < maze.size() - 1 && curr[i][j + 1] != 1 && maze[i][j + 1] == 1) {
            curr[i][j] = 1;
            allPaths(i, j + 1, maze, curr, ans);
            curr[i][j] = 0;
        }
    
        if(i > 0 && curr[i - 1][j] != 1 && maze[i - 1][j] == 1) {
            curr[i][j] = 1;
            allPaths(i - 1, j, maze, curr, ans);
            curr[i][j] = 0;
        }
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int>> ans;
    if(n == 1) {
        vector<int> curr;
        curr.push_back(1);
        ans.push_back(curr);
        return ans;
    }
    vector<vector<int>> curr(n, vector<int> (n, 0));
    if(maze[0][0] == 1) allPaths(0, 0, maze, curr, ans);
    return ans;
}
