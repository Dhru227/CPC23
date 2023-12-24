#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int solve(vector<int> &A, int B) {
        int n = A.size();
        int countSubarrays = 0;
        int currentSum = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            currentSum += A[right];

            while (currentSum >= B) {
                currentSum -= A[left];
                left++;
            }

            countSubarrays += (right - left + 1);
        }

        return countSubarrays;
    }
};

int main() {
    Solution solution;

    cout << "Enter the size of vector A: ";
    int sizeA;
    cin >> sizeA;

    vector<int> A(sizeA);
    cout << "Enter the elements of vector A: ";
    for (int i = 0; i < sizeA; i++) {
        cin >> A[i];
    }

    cout << "Enter the value of B: ";
    int B;
    cin >> B;

    int result = solution.solve(A, B);

    cout << "Number of subarrays with sum at least " << B << ": " << result << endl;

    return 0;
}
