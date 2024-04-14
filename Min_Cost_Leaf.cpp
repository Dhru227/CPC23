#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& A) {
        int res = 0;
        vector<int> stack = {INT_MAX};
        for (int a : A) {
            while (stack.back() <= a) {
                int mid = stack.back();
                stack.pop_back();
                res += mid * min(stack.back(), a);
            }
            stack.push_back(a);
        }
        for (int i = 2; i < stack.size(); ++i) {
            res += stack[i] * stack[i - 1];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {6, 2, 4};
    cout << "Output for arr1: " << sol.mctFromLeafValues(arr1) << endl; // Output: 32

    vector<int> arr2 = {4, 11};
    cout << "Output for arr2: " << sol.mctFromLeafValues(arr2) << endl; // Output: 44

    return 0;
}
