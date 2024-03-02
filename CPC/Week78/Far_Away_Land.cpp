#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    bool isallsame(vector<vector<int>>& grid) {
        int compare = grid[0][0];
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] != compare) {
                    return false;
                }
            }
        }
        return true;
    }

    int maxDistance(vector<vector<int>>& grid) {
        if(isallsame(grid)) {
            return -1;
        }

        vector<bool> a(grid[0].size(), false);
        vector<int> b(grid[0].size(), 0);
        vector<vector<bool>> pushedinqueue(grid.size(), a);
        vector<vector<int>> distance(grid.size(), b);

        queue<pair<int,int>> visit;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]) {
                    visit.push({i, j});
                    pushedinqueue[i][j] = true;
                }
            }
        }

        int dist = 0;
        while(!visit.empty()) {
            int n = visit.size();
            for(int i = 0; i < n; i++) {
                pair<int,int> x = visit.front();
                visit.pop();
                distance[x.first][x.second] = dist;

                if(x.first > 0 && !pushedinqueue[x.first - 1][x.second]) {
                    pushedinqueue[x.first - 1][x.second] = true;
                    visit.push({x.first - 1, x.second});
                }
                if(x.first < (grid.size() - 1) && !pushedinqueue[x.first + 1][x.second]) {
                    pushedinqueue[x.first + 1][x.second] = true;
                    visit.push({x.first + 1, x.second});
                }
                if(x.second > 0 && !pushedinqueue[x.first][x.second - 1]) {
                    pushedinqueue[x.first][x.second - 1] = true;
                    visit.push({x.first, x.second - 1});
                }
                if(x.second < (grid[0].size() - 1) && !pushedinqueue[x.first][x.second + 1]) {
                    pushedinqueue[x.first][x.second + 1] = true;
                    visit.push({x.first, x.second + 1});
                }
            }
            dist++;
        }

        int ans = INT_MIN;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    ans = max(ans, distance[i][j]);
                }
            }
        }
        return ans == INT_MIN ? -1 : ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {{1,0,1},{0,0,0},{1,0,1}};

    int maxDist = solution.maxDistance(grid);
    cout << "Maximum distance to the nearest 0: " << maxDist << endl;

    return 0;
}
