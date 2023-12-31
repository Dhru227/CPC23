#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();

        if (n < 4) {
            return result;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];

                    if (sum < target) {
                        ++left;
                    } else if (sum > target) {
                        --right;
                    } else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == result.back()[2]) ++left;
                        while (left < right && nums[right] == result.back()[3]) --right;
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = sol.fourSum(nums, target);

    cout << "Result:" << endl;
    for (const vector<int>& quadruplet : result) {
        for (int num : quadruplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
