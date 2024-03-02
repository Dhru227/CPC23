#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);
        vector<bool> v(rooms.size(), false);
        while (!q.empty()) {
            int p = q.front();
            v[p] = true;
            for (int i = 0; i < rooms[p].size(); i++) {
                if (v[rooms[p][i]] == false)
                    q.push(rooms[p][i]);
            }
            q.pop();
        }
        for (int i = 0; i < v.size(); i++) {
            if (!v[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<vector<int>> rooms = {
        {1, 3},
        {3, 0, 1},
        {2},
        {0}
    };

    if (solution.canVisitAllRooms(rooms)) {
        cout << "All rooms can be visited starting from room 0." << endl;
    } else {
        cout << "All rooms cannot be visited starting from room 0." << endl;
    }

    return 0;
}
