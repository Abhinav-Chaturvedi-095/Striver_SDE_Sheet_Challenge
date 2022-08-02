vector<int> stringMatch(string &text, string &pat) {
    // Write your code here
    int n = text.length();
      int m = pat.length();
    vector<int> ans;
      int j;
      for (int i = 0; i <= n - m; i++) {

        for (j = 0; j < m; ++j) {
          if (pat[j] != text[i + j]) {
            break;
          }
        }

        if (j == m) {
            ans.push_back(i);
//           cout << "index = " << i << "\n";
        }
      }
    return ans;
}
