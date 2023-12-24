#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxone(vector<int> &A, int B) {
        int n = A.size();
        int left = 0, right = 0;
        int zeroCount = 0;
        int maxLen = 0;
        int startIdx = 0;

        while (right < n) {
            if (A[right] == 0) {
                zeroCount++;
            }

            while (zeroCount > B) {
                if (A[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            int currentLen = right - left + 1;
            if (currentLen > maxLen) {
                maxLen = currentLen;
                startIdx = left;
            }

            right++;
        }

        vector<int> result;
        for (int i = 0; i < maxLen; ++i) {
            result.push_back(startIdx + i);
        }

        return result;
    }
};

int main() {
    Solution solution;

    cout << "Enter the size of vector A: ";
    int sizeA;
    cin >> sizeA;

    vector<int> A(sizeA);
    cout << "Enter the elements of vector A (0 or 1): ";
    for (int i = 0; i < sizeA; i++) {
        cin >> A[i];
    }

    cout << "Enter the value of B: ";
    int B;
    cin >> B;

    vector<int> result = solution.maxone(A, B);

    cout << "Indices of the maximum consecutive ones after flipping at most " << B << " zeros: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
