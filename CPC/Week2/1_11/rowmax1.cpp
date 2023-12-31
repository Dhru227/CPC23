#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int maxCount = 0;
        int maxRow = 0;

        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                count += mat[i][j];
            }
            if (count > maxCount) {
                maxCount = count;
                maxRow = i;
            }
        }

        return {maxRow, maxCount};
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat = {
        {1, 0, 1, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 1, 0, 0},
        {0, 0, 1, 0, 1}
    };

    vector<int> result = sol.rowAndMaximumOnes(mat);

    cout << "Max Row Index: " << result[0] << ", Max Ones Count: " << result[1] << endl;

    return 0;
}
