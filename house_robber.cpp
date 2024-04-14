#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solvebu(vector<int>& nums, int index, vector<int>& dp) {
        int n = nums.size();
        dp[nums.size() - 1] = nums[nums.size() - 1];
        int tempans;
        for (int i = n - 2; i >= 0; i--) {
            if (i + 2 >= n) {
                tempans = 0;
            } else {
                tempans = dp[i + 2];
            }
            int include = nums[i] + tempans;
            int exclude = 0 + dp[i + 1];
            dp[i] = max(include, exclude);
        }
        return dp[index];
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solvebu(nums, 0, dp);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Example 1 Output: " << sol.rob(nums1) << endl;

    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << "Example 2 Output: " << sol.rob(nums2) << endl;

    return 0;
}
