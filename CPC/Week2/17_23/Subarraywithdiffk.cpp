#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }

        int product = 1;
        int count = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            product *= nums[right];

            while (product >= k) {
                product /= nums[left];
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }
};

int main() {
    vector<int> nums1 = {10, 5, 2, 6};
    int k1 = 100;

    Solution solution;

    int result1 = solution.numSubarrayProductLessThanK(nums1, k1);

    cout << "Output for Example 1: " << result1 << endl;

    vector<int> nums2 = {1, 2, 3};
    int k2 = 0;

    int result2 = solution.numSubarrayProductLessThanK(nums2, k2);

    cout << "Output for Example 2: " << result2 << endl;

    return 0;
}
