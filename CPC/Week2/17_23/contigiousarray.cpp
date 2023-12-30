#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, maxLen = 0;
        unordered_map<int, int> seen{{0, -1}};
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 1 ? 1 : -1;
            if (seen.count(sum))
                maxLen = max(maxLen, i - seen[sum]);
            else
                seen[sum] = i;
        }
        return maxLen;
    }
};

int main() {
    vector<int> nums = {0, 1};

    Solution solution;

    int result = solution.findMaxLength(nums);

    cout << "Maximum Length of Contiguous Subarray: " << result << endl;

    return 0;
}
