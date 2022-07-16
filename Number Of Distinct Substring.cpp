#include<bits/stdc++.h>
int distinctSubstring(string &word) {
    //  Write your code here.
     set<string> result ;
    // List All Substrings
    for (int i = 0; i <= word.length(); i++)
        for (int j = 1; j <= word.length()-i; j++)
            // Add each substring in Set
            result.insert(word.substr(i, j));
 
    // Return size of the HashSet
    return result.size();
}
//can solve using trie
