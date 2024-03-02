#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return false;
        }
        if (grid[i][j] != 0) {
            return true;
        }
        grid[i][j] = 1;
        bool ist = true;
        for (auto e : dir) {
            int nx = e[0] + i;
            int ny = e[1] + j;
            if (dfs(nx, ny, grid) == false) {
                ist = false;
            }
        }
        return ist;
    }

    bool bfs(int i, int j, vector<vector<int>>& grid) {
        queue<vector<int>> qp;
        qp.push({i, j});
        bool pos = true;

        while (!qp.empty()) {
            auto t = qp.front();
            qp.pop();
            grid[t[0]][t[1]] = 1;
            for (auto e : dir) {
                int nx = t[0] + e[0];
                int ny = t[1] + e[1];
                if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()) {
                    pos = false;
                } else if (grid[nx][ny] == 1) {
                    continue;
                } else {
                    qp.push({nx, ny});
                }
            }
        }
        return pos;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && bfs(i, j, grid)) {
                    c++;
                }
            }
        }
        return c;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };

    int numIslands = solution.closedIsland(grid);
    cout << "Number of closed islands: " << numIslands << endl;

    return 0;
}
