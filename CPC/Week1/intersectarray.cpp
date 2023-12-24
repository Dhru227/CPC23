#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(const vector<int> &A, const vector<int> &B) {
        vector<int> result;
        int i = 0, j = 0;

        while (i < A.size() && j < B.size()) {
            if (A[i] == B[j]) {
                result.push_back(A[i]);
                i++;
                j++;
            } else if (A[i] < B[j]) {
                i++;
            } else {
                j++;
            }
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

    vector<int> result = solution.intersect(A, B);

    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
