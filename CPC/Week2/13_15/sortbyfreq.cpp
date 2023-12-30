#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;  

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;
        priority_queue<pair<int, int>> maxHeap;

        for (int num : nums) {
            frequencyMap[num]++;
        }

        for (const auto& entry : frequencyMap) {
            maxHeap.push({entry.second, entry.first});
        }

        nums.clear();

        while (!maxHeap.empty()) {
            int frequency = maxHeap.top().first;
            int number = maxHeap.top().second;
            maxHeap.pop();

            for (int i = 0; i < frequency; i++) {
                nums.push_back(number);
            }
        }

        return nums;
    }
};

int main() {
    Solution solution;

    vector<int> input = {3, 1, 1, 2, 2, 4, 4, 4};
    vector<int> result = solution.frequencySort(input);

    cout << "Input: ";
    for (int num : input) {
        cout << num << " ";
    }
    cout << "\nSorted Output: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
