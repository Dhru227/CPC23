#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> posneg(vector<int>& nums) {
        int n = nums.size();
        int negCount = 0;

        // Count negative numbers and initialize the result array
        for (int num : nums) {
            if (num < 0) {
                negCount++;
            }
        }

        vector<int> ans(n, 0);
        int posIndex = 0, negIndex = negCount;

        // Fill the result array with rearranged positive and negative numbers
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                ans[negIndex] = nums[i];
                negIndex++;
            } else {
                ans[posIndex] = nums[i];
                posIndex++;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    vector<int> rearranged1 = solution.posneg(nums1);

    cout << "Input: ";
    for (int num : nums1) {
        cout << num << " ";
    }

    cout << "\nOutput: ";
    for (int num : rearranged1) {
        cout << num << " ";
    }

    vector<int> nums2 = {-1, 3, -2, -4, 7, -5};
    vector<int> rearranged2 = solution.posneg(nums2);

    cout << "\n\nInput: ";
    for (int num : nums2) {
        cout << num << " ";
    }

    cout << "\nOutput: ";
    for (int num : rearranged2) {
        cout << num << " ";
    }

    return 0;
}
