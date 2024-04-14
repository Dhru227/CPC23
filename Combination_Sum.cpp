#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int target) {
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += solve(nums, target - nums[i]);
        }
        return ans;
    }

    int solvedp(vector<int>& nums, int target, vector<int>& dp) {
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;
        if (dp[target] != -1)
            return dp[target];
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += solvedp(nums, target - nums[i], dp);
        }
        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return solvedp(nums, target, dp);
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3};
    int target1 = 4;
    cout << "Example 1 Output: " << sol.combinationSum4(nums1, target1) << endl;

    vector<int> nums2 = {9};
    int target2 = 3;
    cout << "Example 2 Output: " << sol.combinationSum4(nums2, target2) << endl;

    return 0;
}
