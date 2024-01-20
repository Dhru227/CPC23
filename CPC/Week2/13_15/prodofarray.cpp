#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;

        if (n < 1)
            return output;

        int product = 1;

        for (int i = 0; i < n; ++i) {
            product *= nums[i];
            output.push_back(product);
        }

        product = 1;

        for (int i = n - 1; i > 0; --i) {
            output[i] = output[i - 1] * product;
            product *= nums[i];
        }

        output[0] = product;

        return output;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = solution.productExceptSelf(nums);

    cout << "Input Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Output Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
