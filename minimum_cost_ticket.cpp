#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int i) {
        if (i >= days.size()) return 0;

        int cost1 = costs[0] + solve(days, costs, i + 1);

        int passEndDate = days[i] + 6;
        int j = i;
        while (j < days.size() && days[j] <= passEndDate) {
            j++;
        }
        int cost7 = costs[1] + solve(days, costs, j);

        passEndDate = days[i] + 29;
        j = i;
        while (j < days.size() && days[j] <= passEndDate) {
            j++;
        }
        int cost30 = costs[2] + solve(days, costs, j);

        return min(cost1, min(cost7, cost30));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return solve(days, costs, 0);
    }
};

int main() {
    Solution sol;
    vector<int> days1 = {1, 4, 6, 7, 8, 20};
    vector<int> costs1 = {2, 7, 15};
    cout << "Example 1 Output: " << sol.mincostTickets(days1, costs1) << endl;

    vector<int> days2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    vector<int> costs2 = {2, 7, 15};
    cout << "Example 2 Output: " << sol.mincostTickets(days2, costs2) << endl;

    return 0;
}
