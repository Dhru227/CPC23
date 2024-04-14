#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int types_num = unordered_set<int>(candies.begin(), candies.end()).size();
        return min(types_num, static_cast<int>(candies.size() / 2));
    }
};

int main() {
    // Example 1
    vector<int> candies1 = {1, 1, 2, 2, 3, 3};
    Solution s1;
    cout << "Maximum number of different types of candies Alice can eat (Example 1): " << s1.distributeCandies(candies1) << endl;

    // Example 2
    vector<int> candies2 = {1, 1, 2, 3};
    Solution s2;
    cout << "Maximum number of different types of candies Alice can eat (Example 2): " << s2.distributeCandies(candies2) << endl;

    // Example 3
    vector<int> candies3 = {6, 6, 6, 6};
    Solution s3;
    cout << "Maximum number of different types of candies Alice can eat (Example 3): " << s3.distributeCandies(candies3) << endl;

    return 0;
}
