#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;

            while (front < back) {
                int sum = nums[front] + nums[back];

                if (sum < target) {
                    front++;
                } else if (sum > target) {
                    back--;
                } else {
                    vector<int> triplet = {nums[i], nums[front], nums[back]};
                    res.push_back(triplet);

                    while (front < back && nums[front] == triplet[1]) {
                        front++;
                    }

                    while (front < back && nums[back] == triplet[2]) {
                        back--;
                    }
                }
            }

            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                i++;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sol.threeSum(nums);

    cout << "Result:" << endl;
    for (const vector<int>& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
