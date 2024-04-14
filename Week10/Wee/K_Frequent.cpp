#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> counter;
        for (int num : nums) {
            counter[num]++;
        }
        
        std::vector<std::pair<int, int>> sorted(counter.begin(), counter.end());
        std::sort(sorted.begin(), sorted.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second > b.second;
        });
        
        std::vector<int> result;
        for (int i = 0; i < k && i < sorted.size(); ++i) {
            result.push_back(sorted[i].first);
        }
        return result;
    }
};

int main() {
    Solution solution;
    
    std::vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    std::vector<int> result1 = solution.topKFrequent(nums1, k1);
    std::cout << "Output for nums1 and k1: ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> nums2 = {1};
    int k2 = 1;
    std::vector<int> result2 = solution.topKFrequent(nums2, k2);
    std::cout << "Output for nums2 and k2: ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
