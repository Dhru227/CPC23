#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) {
            return -1;  
        }

        if (n == 1 && m == 1) {
            return 1;  
        }

        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));

        q.push({0, 0});
        dist[0][0] = 1;

        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, 1},
            {1, 1}, {1, 0}, {1, -1}, {0, -1}
        };

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int currRow = curr.first;
            int currCol = curr.second;

            for (const auto& dir : directions) {
                int newRow = currRow + dir.first;
                int newCol = currCol + dir.second;

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 0 && dist[newRow][newCol] == -1) {
                    q.push({newRow, newCol});
                    dist[newRow][newCol] = dist[currRow][currCol] + 1;

                    if (newRow == n - 1 && newCol == m - 1) {
                        return dist[newRow][newCol];
                    }
                }
            }
        }

        return -1;  
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};

    int shortestPath = solution.shortestPathBinaryMatrix(grid);
    cout << "Shortest path length: " << shortestPath << endl;

    return 0;
}
