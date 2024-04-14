#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        unordered_map<int, unordered_map<int, int>> cache;
        return dp(0, amount, coins, cache);
    }
    
    int dp(int i, int k, vector<int>& coins, unordered_map<int, unordered_map<int, int>>& cache) {
        if (cache.find(i) != cache.end() && cache[i].find(k) != cache[i].end())
            return cache[i][k];
        
        if (i >= coins.size())
            return 0;
        if (k < 0)
            return 0;
        if (k == 0)
            return 1;
        
        int take = dp(i, k - coins[i], coins, cache);
        int ntake = dp(i + 1, k, coins, cache);
        
        cache[i][k] = take + ntake;
        return cache[i][k];
    }
};

int main() {
    Solution sol;
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 5;
    cout << "Example 1 Output: " << sol.change(amount1, coins1) << endl;
    
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Example 2 Output: " << sol.change(amount2, coins2) << endl;
    
    vector<int> coins3 = {10};
    int amount3 = 10;
    cout << "Example 3 Output: " << sol.change(amount3, coins3) << endl;

    return 0;
}
