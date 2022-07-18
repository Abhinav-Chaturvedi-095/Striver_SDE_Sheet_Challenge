#include<bits/stdc++.h>
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
    //Two pointers + binary search
    const int n = arr.size(), q = queries.size();
    vector<int> ans(q, -1);
    sort(arr.begin(), arr.end());

    for (int i = 0; i < q; i++) {
        const int x = queries[i][0], m = queries[i][1];
        if (m < arr[0]) continue;

        int end = upper_bound(arr.begin(), arr.end(), m) - arr.begin();
        int start = 0;

        int k = 0, cur = 0;
        for (int bit = 31; bit >= 0; bit--) {
            if (x & (1 << bit)) { // hope A[i] this bit == 0
                if (!(arr[start] & (1 << bit))) {
                    k |= 1 << bit;
                    end = lower_bound(arr.begin() + start, arr.begin() + end, cur | (1 << bit)) - arr.begin();
                } else {
                    cur |= 1 << bit;
                }
            } else { // hope: A[i] this bit == 1
                if (start <= end - 1 && (arr[end - 1] & (1 << bit))) {
                    k |= 1 << bit;
                    cur |= 1 << bit;
                    start = lower_bound(arr.begin() + start, arr.begin() + end, cur) - arr.begin();
                }
            }
        }
        ans[i] = k;
    }
    return ans;
}
