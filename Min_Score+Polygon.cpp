#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int j = 2; j < n; ++j) {
            for (int i = j - 2; i >= 0; --i) {
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[j] * A[k]);
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    Solution sol;
    vector<int> values1 = {1, 2, 3};
    cout << "Output for values1: " << sol.minScoreTriangulation(values1) << endl; 

    vector<int> values2 = {3, 7, 4, 5};
    cout << "Output for values2: " << sol.minScoreTriangulation(values2) << endl; 

    vector<int> values3 = {1, 3, 1, 4, 1, 5};
    cout << "Output for values3: " << sol.minScoreTriangulation(values3) << endl; 

    return 0;
}
