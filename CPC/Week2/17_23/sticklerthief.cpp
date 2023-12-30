#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int prevMax = 0;
        int currMax = nums[0];
        
        for (int i = 1; i < n; i++) {
            int temp = currMax;
            currMax = max(prevMax + nums[i], currMax);
            prevMax = temp;
        }
        
        return currMax;
    }
};

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};

    Solution solution;

    int result = solution.rob(nums);

    cout << "Maximum Amount Robbed: " << result << endl;

    return 0;
}
