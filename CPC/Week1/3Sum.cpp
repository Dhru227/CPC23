#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &A, int B) {
        sort(A.begin(), A.end());
        int closestSum = INT_MAX;
        long long minDiff = LLONG_MAX;  

        for (int i = 0; i < A.size() - 2; ++i) {
            int left = i + 1;
            int right = A.size() - 1;

            while (left < right) {
                long long currentSum = (long long)A[i] + A[left] + A[right];
                long long currentDiff = abs(currentSum - B);

                if (currentDiff < minDiff) {
                    minDiff = currentDiff;
                    closestSum = currentSum;
                }

                if (currentSum < B) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closestSum;
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<int> input = {-1, 2, 1, -4};
    int target = 1;

    int result = solution.threeSumClosest(input, target);

    cout << "The closest sum to " << target << " is: " << result << endl;

    return 0;
}
