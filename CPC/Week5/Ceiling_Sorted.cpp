#include <iostream>
using namespace std;

int ceilSearch(int arr[], int low, int high, int x) {
    if (sizeof(arr) / sizeof(arr[0]) == 0) return -1;
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == x) return mid;
        else if (x < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

int main() {
    int arr[] = { 1, 2, 8, 10, 10, 12, 19 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;
    int index = ceilSearch(arr, 0, n - 1, x);
    if (index == -1) cout << "Ceiling of " << x << " does not exist in an array";
    else cout << "Ceiling of " << x << " is " << arr[index];
    return 0;
}
