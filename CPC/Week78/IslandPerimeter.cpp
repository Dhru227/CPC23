#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int count=0;
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int ans=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1){
                    ans+=4;
                    if(i>0 && grid[i-1][j]==1) ans-=2;
                    if(j>0 && grid[i][j-1]==1) ans-=2;
                }
            }
        }
        return ans; 
    }
};

int main() {
    Solution solution;

    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    int perimeter = solution.islandPerimeter(grid);
    cout << "Perimeter of the island: " << perimeter << endl;

    return 0;
}
