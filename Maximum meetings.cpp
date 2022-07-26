#include <bits/stdc++.h>
struct myComp {
  bool operator() (const pair<pair<int,int>,int> &a,const pair<pair<int,int>,int> &b) const {
      if(a.first.second < b.first.second) return 1;
      if(a.first.second > b.first.second) return 0;
      if(a.second < b.second) return 1;
      return 0;
  }  
};
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    set<pair<pair<int,int>,int>,myComp> s;
    // cout << "Hii" << endl;
    for(int i = 0; i < start.size(); i++) {
        s.insert({{start[i],end[i]},i + 1});
    }
    // for(auto i : s) cout << i.first.first << " " << i.first.second << endl;
    vector<int> ans;
    int endd = -1e8;
    for(auto i : s) {
        if(i.first.first > endd) {
            endd = i.first.second;
            ans.push_back(i.second);
        }
    }
    return ans;
}
