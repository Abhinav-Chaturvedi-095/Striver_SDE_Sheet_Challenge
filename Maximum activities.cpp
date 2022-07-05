#include<bits/stdc++.h>
struct meeting {
   int start;
   int end;
};
bool static comparator(struct meeting m1, meeting m2) {
         if (m1.end < m2.end) return true;
         return false;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n=start.size();
    struct meeting meet[n];
    for (int i = 0; i < n; i++){
         meet[i].start = start[i], meet[i].end = finish[i];
      }
    sort(meet, meet + n, comparator);
    int limit = meet[0].end;
    int count=1;
    for (int i = 1; i < n; i++) {
         if (meet[i].start >= limit) {
            limit = meet[i].end;
            count++;
         }
      }
    return count;
}
