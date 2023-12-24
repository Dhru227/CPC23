#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &A, int B) {
        int n = A.size();
        int j = 0;

        for (int i = 0; i < n; i++) {
            if (A[i] != B) {
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
    cout << "Enter the elements of vector A: ";
    for (int i = 0; i < sizeA; i++) {
        cin >> A[i];
    }

    cout << "Enter the element to be removed: ";
    int elementToRemove;
    cin >> elementToRemove;

    int newSize = solution.removeElement(A, elementToRemove);

    cout << "After removing " << elementToRemove << ", the updated vector A is: ";
    for (int i = 0; i < newSize; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
