#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

class Solution {
public:
    void merge(vector<int> &A, vector<int> &B) {
        const int n = A.size(), m = B.size();

        for (int i = 0; i < m; i++) {
            A.push_back(0);
        }

        int i = n - 1, j = m - 1, k = m + n - 1;

        while (j >= 0 && i >= 0) {
            if (A[i] >= B[j]) {
                A[k] = A[i];
                A[i] = 0;
                i--;
                k--;
            } else {
                A[k] = B[j];
                j--;
                k--;
            }
        }

        while (j >= 0) {
            A[j] = B[j];
            j--;
        }

        sort(A.begin(), A.end());
    }
};

int main() {
    Solution solution;

    vector<int> A = {1, 3, 5, 0, 0, 0};  
    vector<int> B = {2, 4, 6};

    solution.merge(A, B);

    cout << "Merged and sorted array: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
