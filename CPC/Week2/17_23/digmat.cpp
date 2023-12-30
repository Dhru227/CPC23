#include <iostream>
#include <vector>
#include <map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        
        vector<int> res;
        map<int, vector<int>> mp;
        
        for(int i = 0 ; i < matrix.size() ; i++) 
            for(int j = 0 ; j < matrix[0].size() ; j++)
                mp[i + j].push_back(matrix[i][j]);
        
        for(auto i : mp) {
            if((i.first)%2 == 0) 
                reverse(i.second.begin(), i.second.end()); 
            
            for(auto k : i.second) res.push_back(k);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution solution;
    vector<int> result = solution.findDiagonalOrder(matrix);

    cout << "Diagonal Order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
