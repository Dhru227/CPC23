#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int sum = arr[i];

            if (sum == k)
                ans++;

            for (int j = i + 1; j < n; j++) {
                sum += arr[j];

                if (sum == k)
                    ans++;
            }
        }

        return ans;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 9;

    Solution solution;

    int result = solution.subarraySum(arr, k);

    cout << "Count of Subarrays with Sum " << k << ": " << result << endl;

    return 0;
}
