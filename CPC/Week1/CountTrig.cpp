#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

class Solution {
public:
    int nTriang(vector<int> &A) {
        sort(A.begin(), A.end());
        int n = A.size();
        int count = 0;
        
        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (A[i] + A[j] > A[k]) {
                    count = (count + (j - i)) % MOD;
                    j--;
                } else {
                    i++;
                }
            }
        }
        return count;
    }


};

int main() {
    Solution solution;

    vector<int> input = {1, 2, 3, 4, 5};
    int result = solution.nTriang(input);

    cout << "Number of triangles: " << result << endl;

    return 0;
}
