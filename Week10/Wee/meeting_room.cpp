#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        
        pq.push(intervals[0][1]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        
        return pq.size();
    }
};

int main() {
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    Solution s1;
    cout << "Minimum number of conference rooms required for intervals1: " << s1.minMeetingRooms(intervals1) << endl;
    
    vector<vector<int>> intervals2 = {{1, 18}, {18, 23}, {15, 29}, {4, 15}, {2, 11}, {5, 13}};
    Solution s2;
    cout << "Minimum number of conference rooms required for intervals2: " << s2.minMeetingRooms(intervals2) << endl;
    
    return 0;
}
