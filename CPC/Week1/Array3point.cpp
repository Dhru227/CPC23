#include <iostream>
#include <vector>
#include <climits> 
#include <cmath>   

using namespace std;

class Solution {
public:
    int minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
        int i = 0, j = 0, k = 0;
        int minDiff = INT_MAX;

        while (i < A.size() && j < B.size() && k < C.size()) {
            int maxVal = max(abs(A[i] - B[j]), max(abs(B[j] - C[k]), abs(C[k] - A[i])));
            minDiff = min(minDiff, maxVal);

            if (A[i] <= B[j] && A[i] <= C[k]) {
                i++;
            } else if (B[j] <= A[i] && B[j] <= C[k]) {
                j++;
            } else {
                k++;
            }
        }

        return minDiff;
    }
};

int main() {
    Solution solution;

    cout << "Enter the size of vector A: ";
    int sizeA;
    cin >> sizeA;

    vector<int> A(sizeA);
    cout << "Enter the elements of vector A in sorted order: ";
    for (int i = 0; i < sizeA; i++) {
        cin >> A[i];
    }

    cout << "Enter the size of vector B: ";
    int sizeB;
    cin >> sizeB;

    vector<int> B(sizeB);
    cout << "Enter the elements of vector B in sorted order: ";
    for (int i = 0; i < sizeB; i++) {
        cin >> B[i];
    }

    cout << "Enter the size of vector C: ";
    int sizeC;
    cin >> sizeC;

    vector<int> C(sizeC);
    cout << "Enter the elements of vector C in sorted order: ";
    for (int i = 0; i < sizeC; i++) {
        cin >> C[i];
    }

    int result = solution.minimize(A, B, C);

    cout << "Minimum absolute difference among triplets: " << result << endl;

    return 0;
}
