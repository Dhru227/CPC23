#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for (int i = 2; i < n; i++) {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        return min(cost[n - 1], cost[n - 2]);
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> cost1 = {10, 15, 20};
    cout << "Example 1 Output: " << sol.minCostClimbingStairs(cost1) << endl;

    // Example 2
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Example 2 Output: " << sol.minCostClimbingStairs(cost2) << endl;

    return 0;
}
