#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
    if (n == 0)
        return false;
 
    // traverse through the matrix
//use binary search for sorted  
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            if (mat[i][j] == target) {
                return true;
            }
    }
 
    return false;
}
