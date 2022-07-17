#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    //sliding window
    int n = input.size();
    int res = 0;  
    for (int i = 0; i < n; i++) {
        vector<bool> visited(256);  
 
        for (int j = i; j < n; j++) {
            if (visited[input[j]] == true)
                break;
            else {
                res = max(res, j - i + 1);
                visited[input[j]] = true;
            }
        }
         visited[input[i]] = false;
    }
    return res;
}
