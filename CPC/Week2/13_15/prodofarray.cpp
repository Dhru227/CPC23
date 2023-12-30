#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> output(n, 1); 

        for (int i = 1; i < n; i++) {
            output[i] = output[i - 1] * nums[i - 1];
        }

        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            output[i] *= right;
            right *= nums[i];
        }

        return output;
    }
};

int main() {
    Solution solution;


    vector<int> input = {1, 2, 3, 4};
    vector<int> result = solution.productExceptSelf(input);

    cout << "Input: ";
    for (int num : input) {
        std::cout << num << " ";
    }
    cout << "\nOutput: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
