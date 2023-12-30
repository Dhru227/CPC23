#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int prod = 1;

        for (int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            maxi = max(prod, maxi);
            if (prod == 0)
                prod = 1;
        }

        prod = 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            prod *= nums[i];
            maxi = max(prod, maxi);
            if (prod == 0)
                prod = 1;
        }

        return maxi;
    }
};

int main() {
    vector<int> nums = {2, 3, -2, 4};

    Solution solution;

    int result = solution.maxProduct(nums);

    cout << "Maximum Product: " << result << endl;

    return 0;
}
