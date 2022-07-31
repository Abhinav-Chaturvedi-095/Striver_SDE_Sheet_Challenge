#include <bits/stdc++.h>

bool isSafe(int node, int color[], vector<vector<int>> &graph, int n, int col) {
  for (int k = 0; k < n; k++) {
    if (k != node && graph[k][node] == 1 && color[k] == col) {
      return false;
    }
  }
  return true;
}
bool solve(int node, int color[], int m, int n, vector<vector<int>> &graph) {
    if (node == n) return true;

    for (int i = 1; i <= m; i++) {
        if (isSafe(node, color, graph, n, i)) {
            color[node] = i;
            if (solve(node + 1, color, m, n, graph)) return true;
            color[node] = 0;
        }

     }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    int color[n] = {0};
    
    if(solve(0, color, m, n, mat)) return "YES";
    return "NO";
    
}
