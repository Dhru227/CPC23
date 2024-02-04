#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if(nums.empty()) return ans;
        int t1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int t2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(t1 == t2) return ans;
        ans[0] = t1;
        ans[1] = t2 - 1;
        return ans;
    }
};

int main() {
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements in sorted order: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << "Enter the target element: ";
    cin >> target;
    
    Solution obj;
    vector<int> result = obj.searchRange(nums, target);
    
    cout << "Range of target element in the array: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
