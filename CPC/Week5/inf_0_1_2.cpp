#include <bits/stdc++.h>
using namespace std;

int indexOfFirstOne(vector<int>& arr, int l, int h) {
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (arr[mid] == 1 && (mid == 0 || arr[mid - 1] == 0)) {
            return mid;
        } else if (arr[mid] == 1) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1; 
}

int posOfFirstOne(vector<int>& arr) {
    int l = 0, h = 1;
    while (arr[h] == 0) {
        l = h;
        h = 2 * h;
    }
    return indexOfFirstOne(arr, l, h);
}

int main() {
    vector<int> arr1 = {0, 0, 1, 1, 1, 1};
    vector<int> arr2 = {1, 1, 1, 1, 1, 1};
    cout << posOfFirstOne(arr1) << endl;
    cout << posOfFirstOne(arr2) << endl;
    return 0;
}
