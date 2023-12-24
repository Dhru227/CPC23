#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int solve(vector<int> &A, int B) {
        map<int, int> m;
        for (int i = 0; i < A.size(); i++) {
            if (m[A[i]]) {
                return 1;
            } else {
                m[A[i] - B]++;
                m[A[i] + B]++;
            }
        }
        return 0;
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<int> input = {1, 5, 3, 2, 7};
    int difference = 2;

    int result = solution.solve(input, difference);

    if (result) {
        cout << "There exist two elements with an absolute difference of " << difference << "." << endl;
    } else {
        cout << "No such pair found." << endl;
    }

    return 0;
}
