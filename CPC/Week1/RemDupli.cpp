#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &A) {
        int n = A.size();

        if (n == 0 || n == 1) {
            return n;
        }

        int j = 0;

        for (int i = 0; i < n - 1; i++) {
            if (A[i] != A[i + 1]) {
                A[j++] = A[i];
            }
        }

        A[j++] = A[n - 1];

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

    cout << "After removing duplicates, the updated vector A is: ";
    for (int i = 0; i < newSize; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
