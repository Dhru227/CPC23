#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int ans = INT_MAX;

        unordered_map<string, int> map;

        for (int i = 0; i < c; i++) {
            ans = min(ans, rec(0, i, matrix, map));
        }

        return ans;
    }

private:
    int rec(int i, int j, vector<vector<int>>& arr, unordered_map<string, int>& map) {
        if (i == arr.size()) return 0;
        if (j < 0 || j >= arr[0].size()) return INT_MAX;

        string key = to_string(i) + "Shiva" + to_string(j);
        if (map.find(key) != map.end()) {
            return map[key];
        }

        int ops1 = rec(i + 1, j - 1, arr, map);
        int ops2 = rec(i + 1, j, arr, map);
        int ops3 = rec(i + 1, j + 1, arr, map);

        map[key] = arr[i][j] + min(ops1, min(ops2, ops3));
        return arr[i][j] + min(ops1, min(ops2, ops3));
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << "Minimum falling path sum: " << sol.minFallingPathSum(matrix) << endl;
    return 0;
}
