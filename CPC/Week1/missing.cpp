#include <bits/stdc++.h>

using namespace std;

int findMissingNumber(int arr[], int n) {
    int sumTotal = (n + 1) * (n + 2) / 2;

    int arraySum = 0;
    for (int i = 0; i < n; i++) {
        arraySum += arr[i];
    }

    int missingNumber = sumTotal - arraySum;

    return missingNumber;
}

int main() {
    int n;

    cout << "Enter the size of the array (N-1): ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    int missingNumber = findMissingNumber(arr, n);

    cout << "The missing number is: " << missingNumber << endl;

    return 0;
}
