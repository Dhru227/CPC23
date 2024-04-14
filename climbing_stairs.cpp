#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int climbStairs(int n, unordered_map<int, int>& memo) {
        if (n == 0 || n == 1) {
            return 1;
        }
        if (memo.find(n) == memo.end()) {
            memo[n] = climbStairs(n - 1, memo) + climbStairs(n - 2, memo);
        }
        return memo[n];
    }

    int climbStairs(int n) {
        unordered_map<int, int> memo;
        return climbStairs(n, memo);
    }
};

int main() {
    Solution sol;
    int n1 = 2;
    cout << "Example 1 Output: " << sol.climbStairs(n1) << endl;

    int n2 = 3;
    cout << "Example 2 Output: " << sol.climbStairs(n2) << endl;

    return 0;
}
