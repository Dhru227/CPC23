#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int low = INT_MAX, mid = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (nums[i] > mid) {
                return true;
            } else if (nums[i] < low) {
                low = nums[i];
            } else if (nums[i] > low && nums[i] < mid) {
                mid = nums[i];
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {5, 4, 3, 2, 1};

    cout << "Result 1: " << (sol.increasingTriplet(nums1) ? "true" : "false") << endl;  
    cout << "Result 2: " << (sol.increasingTriplet(nums2) ? "true" : "false") << endl;  

    return 0;
}
