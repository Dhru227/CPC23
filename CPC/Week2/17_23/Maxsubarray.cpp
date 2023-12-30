#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n); 
        dp[0] = nums[0];
        int maxSum = dp[0];

        for (int i = 1; i < n; ++i) {
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);  
            maxSum = max(maxSum, dp[i]); 
        }
        
        return maxSum;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution solution;
    
    int result = solution.maxSubArray(nums);

    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}
