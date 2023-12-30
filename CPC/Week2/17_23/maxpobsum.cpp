#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int currsum = nums[0];
        int maxsum = nums[0];
        int i = 1;
        
        while (i < n) {
            if (nums[i] > nums[i - 1]) {
                currsum += nums[i];
            } else {
                maxsum = max(maxsum, currsum);
                currsum = nums[i];
            }
            i++;
        }
        
        maxsum = max(maxsum, currsum);
        return maxsum;
    }
};

int main() {
    vector<int> nums = {10, 20, 30, 5, 10, 50};

    Solution solution;

    int result = solution.maxAscendingSum(nums);

    cout << "Maximum Ascending Sum: " << result << endl;

    return 0;
}
