#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &A) {
        int low = 0;
        int high = A.size() - 1;
        int i = 0;

        while (i <= high) {
            if (A[i] == 0) {
                swap(A[i], A[low]);
                low++;
                i++;
            } else if (A[i] == 2) {
                swap(A[i], A[high]);
                high--;
            } else {
                i++;
            }
        }
    }
};

int main() {
    Solution solution;

    cout << "Enter the size of vector A: ";
    int sizeA;
    cin >> sizeA;

    vector<int> A(sizeA);
    cout << "Enter the elements of vector A (0, 1, or 2): ";
    for (int i = 0; i < sizeA; i++) {
        cin >> A[i];
    }

    solution.sortColors(A);

    cout << "After sorting, the updated vector A is: ";
    for (int i = 0; i < sizeA; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
