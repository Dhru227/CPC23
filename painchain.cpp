#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

class Solution {
public:
    int n, dp[1005];
    pii a[1005];

    int solve(int i) {
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        for(int j=i+1; j<=n; j++){
            if(a[j].first > a[i].second){
                ans = max(ans, solve(j));
            }
        }
        return dp[i] = 1 + ans;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp, -1, sizeof(dp));
        n = pairs.size();
        for(int i=1; i<=n; i++) {
            a[i].first = pairs[i-1][0];
            a[i].second = pairs[i-1][1];
        }
        sort(a+1, a+1+n);
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = max(ans, solve(i));
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> pairs1 = {{1,2},{2,3},{3,4}};
    cout << sol.findLongestChain(pairs1) << endl; 

    vector<vector<int>> pairs2 = {{1,2},{7,8},{4,5}};
    cout << sol.findLongestChain(pairs2) << endl; 

    return 0;
}
