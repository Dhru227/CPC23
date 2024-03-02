#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        
        for (const auto& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int dependency = prerequisite[1];
            graph[dependency].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int completedCourses = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            completedCourses++;
            for (int neighbor : graph[course]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return completedCourses == numCourses;
    }
};

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    Solution solution;
    bool canFinish = solution.canFinish(numCourses, prerequisites);

    if (canFinish) {
        cout << "All courses can be finished." << endl;
    } else {
        cout << "Not all courses can be finished due to cyclic dependencies." << endl;
    }

    return 0;
}
