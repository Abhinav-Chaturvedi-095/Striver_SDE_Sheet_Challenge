#include <bits/stdc++.h>

static bool myComp(pair<int,int> &a, pair<int,int> &b) {
    if(a.first < b.first) return 1;
    if(a.first > b.first) return 0;
    if(a.second > b.second) return 1;
    return 0;
}

int jobScheduling(vector<vector<int>> &jobs)
{
    vector<pair<int,int>> job;
    for(int i = 0; i < jobs.size(); i++) {
        job.push_back({jobs[i][0],jobs[i][1]});
    }
    sort(job.begin(), job.end(), myComp);
    int profit = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int time = 0;
    for(int i = 0; i < job.size(); i++) {
        if(!pq.size()) {
            profit += job[i].second;
            pq.push(job[i].second);
            time++;
        } else {
            if(job[i].first > time) {
                profit += job[i].second;
                pq.push(job[i].second);
                time++;
            } else {
                if(pq.top() < job[i].second) {
                    profit -= pq.top();
                    profit += job[i].second;
                    pq.pop();
                    pq.push(job[i].second);
                }
            }
        }
    }
    return profit;
    
}
