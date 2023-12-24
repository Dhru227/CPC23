#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &A) {
        int n = A.size();

        if (n <= 2) {
            return n;
        }

        int j = 2;

        for (int i = 2; i < n; i++) {
            if (A[i] != A[j - 1] || A[i] != A[j - 2]) {
                A[j++] = A[i];
            }
        }

        return j;
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

    int newSize = solution.removeDuplicates(A);

    cout << "After allowing at most two occurrences, the updated vector A is: ";
    for (int i = 0; i < newSize; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
