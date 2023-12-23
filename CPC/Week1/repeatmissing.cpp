#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> repeatedNumber(const vector<int> &A);
};

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    vector<int> modifiedA = A;  

    int repeat = 0;

    for (int i = 0; i < n; i++) {
        int temp = abs(modifiedA[i]) - 1;
        if (modifiedA[temp] < 0) {
            repeat = temp + 1;
            continue;
        }
        modifiedA[temp] = -modifiedA[temp];
    }

    int missing = 0;
    for (int i = 0; i < n; i++) {
        if (modifiedA[i] > 0) {
            missing = i + 1;
            break;
        }
    }

    return {repeat, missing};
}

int main() {
    Solution solution;
    vector<int> input = {3, 1, 2, 5, 3};

    vector<int> result = solution.repeatedNumber(input);

    cout << "Repeated number is: " << result[0] << endl;
    cout << "Missing number is: " << result[1] << endl;

    return 0;
}
