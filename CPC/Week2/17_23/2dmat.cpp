#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0, r = 0, c = n - 1;
        while (r < m && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            }
            matrix[r][c] > target ? c-- : r++;
        }
        return false;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    int target1 = 5; 
    int target2 = 15;

    bool result1 = solution.searchMatrix(matrix, target1);
    bool result2 = solution.searchMatrix(matrix, target2);

    cout << "Target " << target1 << " is " << (result1 ? "found" : "not found") << " in the matrix.\n";
    cout << "Target " << target2 << " is " << (result2 ? "found" : "not found") << " in the matrix.\n";

    return 0;
}
