#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(const vector<int>& set, int sum) {
    int n = set.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; ++i)
        dp[i][0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (set[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
        }
    }
    return dp[n][sum];
}

int main() {
    vector<int> set = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    if (isSubsetSum(set, sum))
        cout << "Found a subset with the given sum." << endl;
    else
        cout << "No subset with the given sum." << endl;

    return 0;
}
