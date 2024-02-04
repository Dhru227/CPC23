#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void mergeArrays(vector<int>& mPlusN, vector<int>& N, int m, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (mPlusN[i] > N[j]) {
                mPlusN[k--] = mPlusN[i--];
            } else {
                mPlusN[k--] = N[j--];
            }
        }

        while (j >= 0) {
            mPlusN[k--] = N[j--];
        }
    }
};

int main() {
    vector<int> mPlusN = {2, 8, -1, -1, -1, 13, -1, 15, 20};
    vector<int> N = {5, 7, 9, 25};
    int m = 4, n = N.size();
    
    Solution sol;
    sol.mergeArrays(mPlusN, N, m, n);

    cout << "Merged array: ";
    for (int num : mPlusN) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
