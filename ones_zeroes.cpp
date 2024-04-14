#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dp[601][101][101];

    int dfs(int i, int m, int n, vector<string> &strs) {
        int x = strs.size();
        if (i >= x) return 0;
        if (dp[i][m][n] != -1) return dp[i][m][n];
        int zc = count(strs[i].begin(), strs[i].end(), '0');
        int oc = size(strs[i]) - zc;
        if (m - zc >= 0 && n - oc >= 0) {
            return dp[i][m][n] = max(1 + dfs(i + 1, m - zc, n - oc, strs), dfs(i + 1, m, n, strs));
        } else {
            return dp[i][m][n] = dfs(i + 1, m, n, strs);
        }
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return dfs(0, m, n, strs);
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    cout << sol.findMaxForm(strs, m, n) << endl; 

    return 0;
}
