#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &A) {
        int left = 0, right = A.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int width = right - left;
            int height = min(A[left], A[right]);
            maxArea = max(maxArea, width * height);

            if (A[left] < A[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
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

    int result = solution.maxArea(A);

    cout << "Maximum area of water that can be trapped: " << result << endl;

    return 0;
}
