#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0;
        int oddCount = 0;
        unordered_map<int, int> freqmap;
        freqmap[0] = 1;

        for (int num : nums) {
            if (num % 2 == 1)
                oddCount++;

            if (freqmap.find(oddCount - k) != freqmap.end())
                count += freqmap[oddCount - k];

            freqmap[oddCount]++;
        }

        return count;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    Solution solution;

    int result = solution.numberOfSubarrays(nums, k);

    cout << "Number of Subarrays with " << k << " Odd Numbers: " << result << endl;

    return 0;
}
