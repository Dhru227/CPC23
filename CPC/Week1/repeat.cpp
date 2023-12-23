#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void findTwoRepeatingElements(int arr[], int n) {
    sort(arr, arr + n);

    cout << "The two repeating elements are: ";

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            cout << arr[i] << " ";
        }
    }
}

int main() {
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    findTwoRepeatingElements(arr, n);

    return 0;
}
