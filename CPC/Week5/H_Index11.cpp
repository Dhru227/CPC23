#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        if (!n) return 0;
        int low = 0, high = n - 1;
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (c[mid] >= n - mid) {
                ans = n - mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> citations1 = {0, 1, 3, 5, 6};
    Solution sol;
    cout << "hIndex for citations1: " << sol.hIndex(citations1) << endl;

    vector<int> citations2 = {0, 1, 2, 5, 6};
    cout << "hIndex for citations2: " << sol.hIndex(citations2) << endl;

    return 0;
}
