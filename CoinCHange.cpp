#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        int dp[++n];
        dp[0] = 0;
        sort(begin(coins), end(coins));
        for (int i = 1; i < n; i++) {
            dp[i] = INT_MAX;
            for (int c: coins) {
                if (i - c < 0) break;
                if (dp[i - c] != INT_MAX) dp[i] = min(dp[i], 1 + dp[i - c]);
            }
        }
        return dp[--n] == INT_MAX ? -1 : dp[n];
    }
};

int main() {
    vector<int> coins = {1, 2, 3};
    int n = 5;

    Solution sol;
    cout << sol.coinChange(coins, n) << endl;

    return 0;
}
