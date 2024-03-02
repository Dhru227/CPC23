#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& grid1, int i, int j, int color) {
        if (grid1[i][j] != 1) return color;
        
        grid1[i][j] = color;

        solve(grid1, i, j + 1, color); // right
        solve(grid1, i + 1, j, color);  // down
        solve(grid1, i - 1, j, color);  // up
        solve(grid1, i, j - 1, color);  // left

        return color + 1;
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0, first_color = 2;
        vector<vector<int>> grid1;

        // Converting char grid to int grid
        for (int i = 0; i < grid.size() + 2; i++) {
            vector<int> t(grid[0].size() + 2, 0);
            grid1.push_back(t);
        }

        for (int i = 1; i < grid1.size() - 1; i++) {
            for (int j = 1; j < grid1[0].size() - 1; j++) {
                grid1[i][j] = (int)grid[i - 1][j - 1] - 48;
            }
        }

        int color = 10;
        for (int i = 1; i < grid1.size() - 1; i++) {
            for (int j = 1; j < grid1[0].size() - 1; j++) {
                if (grid1[i][j] == 1)
                    color = solve(grid1, i, j, color);
            }
        }
        return color - 10;
    }
};

int main() {
    Solution solution;

    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    int numIslands = solution.numIslands(grid);
    cout << "Number of islands: " << numIslands << endl;

    return 0;
}
